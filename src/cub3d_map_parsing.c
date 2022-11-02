/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/02 16:59:31 by mgulenay         ###   ########.fr       */
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

void	*cub3d_map_end(t_data *new, char *line, int fd)
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
			return (cub3d_error_clean(new, fd));
	}
	return (EXIT_SUCCESS);
}

int	cub3d_map_parsing(t_data *data, char *line, int fd)
{
	//error management
	int	flag;

	flag = 0;
	while (line != NULL)
	{
		if (ft_strncmp("NO ", line, 3) == 0)
			data->tex.no.path = ft_strtrim(&line[3], "\n");
		else if (ft_strncmp("SO ", line, 3) == 0)
			data->tex.so.path = ft_strtrim(&line[3], "\n");
		else if (ft_strncmp("EA ", line, 3) == 0)
			data->tex.ea.path = ft_strtrim(&line[3], "\n");
		else if (ft_strncmp("WE ", line, 3) == 0)
			data->tex.we.path = ft_strtrim(&line[3], "\n");
		else if (ft_strncmp("F", line, 1) == 0)
			cub3d_set_colours(data, &line[2], 0);
		else if (ft_strncmp("C", line, 1) == 0)
		{
			cub3d_set_colours(data, &line[2], 1);
			flag = 1;
		}
		else if (ft_strncmp("\n", line, 1) != 0 && flag == 1)
		{
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	cub3d_map_init(data);
	cub3d_fill_map(data, line, data->map, 0);
	cub3d_map_end(data, line, fd);
	return (EXIT_SUCCESS);
}
