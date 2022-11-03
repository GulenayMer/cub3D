/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:12:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/03 17:45:50 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	type;

	y = 0;
	while (y < data->map->count_y)
	{
		x = 0;
		type = cub3d_check_square(data, x, y);
		while (type != TYPE_NEWLINE && type != TYPE_END)
		{
			if (check_walls(data, x, y))
				return (EXIT_FAILURE);
			if (check_spaces(data, x, y))
				return (EXIT_FAILURE);
			x += 1;
			type = cub3d_check_square(data, x, y);
		}
		y += 1;
	}
	return (EXIT_SUCCESS);
}

int	cub3d_check_tex_path(char *path)
{
	int	fd;

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
