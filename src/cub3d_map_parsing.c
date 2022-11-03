/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/03 16:16:31 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_check_max_len(char *map)
{
	int	fd;
	size_t len;
	char	*line;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (ft_strlen(line) > len)
			len = ft_strlen(line);
		}
	}
	close(fd);
	return ((int) len);
}

void	cub3d_map_init(t_data *new)
{
	new->map = matrix_init(new->xlen, 1, sizeof(t_cell));
	if (new->map == NULL)
	{
		new->error_check = EXIT_FAILURE;
		return ;
	}
}

int	cub3d_map_end(t_data *new, char *line, int fd)
{
	int	y;

	y = 0;
	while (line != NULL)
	{
		y += 1;
		free(line);
		line = get_next_line(fd);
		cub3d_fill_map(new, line, new->map, y);
		if (new->error_check == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void cub3d_validator_init(t_data *data)
{
	data->tex.val.no = 0;
	data->tex.val.so = 0;
	data->tex.val.we = 0;
	data->tex.val.ea = 0;
	data->tex.val.c = 0;
	data->tex.val.f = 0;
}

int	cub3d_validator(t_data *data)
{
	int error;

	if (data->tex.val.no != 1)
		error = 1;
	else if (data->tex.val.so != 1)
		error = 1;
	else if (data->tex.val.we != 1)
		error = 1;
	else if (data->tex.val.ea != 1)
		error = 1;
	else if (data->tex.val.c != 1)
		error = 1;
	else if (data->tex.val.f != 1)
		error = 1;
	else
		error = 0;
	if (error == 0)
		return (EXIT_SUCCESS);
	else
	{
		ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
		return (EXIT_FAILURE);
	}
}

int cub3d_check_tex_path(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(STDERR_FILENO, INVALID_PATH, path);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	cub3d_map_parsing(t_data *data, char *line, int fd)
{
	//error management
	int	flag;

	flag = 0;
	cub3d_validator_init(data);
	while (line != NULL)
	{
		if (ft_strncmp("NO ", line, 3) == 0)
		{
			data->tex.no.path = ft_strtrim(&line[3], "\n");
			if (cub3d_check_tex_path(data->tex.no.path) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			data->tex.val.no += 1;
		}
		else if (ft_strncmp("SO ", line, 3) == 0)
		{
			data->tex.so.path = ft_strtrim(&line[3], "\n");
			if (cub3d_check_tex_path(data->tex.so.path) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			data->tex.val.so += 1;
		}
		else if (ft_strncmp("EA ", line, 3) == 0)
			{
			data->tex.ea.path = ft_strtrim(&line[3], "\n");
			if (cub3d_check_tex_path(data->tex.ea.path) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			data->tex.val.ea += 1;
		}
		else if (ft_strncmp("WE ", line, 3) == 0)
		{
			data->tex.we.path = ft_strtrim(&line[3], "\n");
			if (cub3d_check_tex_path(data->tex.we.path) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			data->tex.val.we += 1;
		}
		else if (ft_strncmp("F", line, 1) == 0)
		{
			if (cub3d_set_colours(data, &line[2], 1) == EXIT_FAILURE)
			{
				ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
				return (EXIT_FAILURE);
			}
			data->tex.val.f += 1;
		}
		else if (ft_strncmp("C", line, 1) == 0)
		{
			if (cub3d_set_colours(data, &line[2], 1) == EXIT_FAILURE)
			{
				ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
				return (EXIT_FAILURE);
			}
			data->tex.val.c += 1;
			flag = 1;
		}
		else if (ft_strncmp("\n", line, 1) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else if (ft_strncmp("\n", line, 1) != 0 && flag == 1)
		{
			break ;
		}
		else
		{
			data->error_check = 1;
			ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (data->error_check == 1)
		return (EXIT_FAILURE);
	if (cub3d_validator(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cub3d_map_init(data);
	cub3d_fill_map(data, line, data->map, 0);
	if (cub3d_map_end(data, line, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
