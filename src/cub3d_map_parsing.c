/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/02 12:07:47 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"


void	cub3d_map_init(t_data *new, char *line)
{
	new->xlen = ft_strlen(line) + 1;
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
		line = get_next_line(fd, 0);
		cub3d_fill_map(new, line, new->map, y);
		if (new->error_check == EXIT_FAILURE)
			return (cub3d_error_clean(new, line, fd));
	}
	return (EXIT_SUCCESS);
}

int	cub3d_get_tex_path(t_data *data, char *line, int fd)
{
	int	flag;

	flag = 0;
	while (line != NULL)
	{
		if (ft_strncmp("NO ", line, 3) == 0)
			data->tex.no.path = &line[3];
		else if (ft_strncmp("SO ", line, 3) == 0)
			data->tex.so.path = &line[3];
		else if (ft_strncmp("EA ", line, 3) == 0)
			data->tex.ea.path = &line[3];
		else if (ft_strncmp("WE ", line, 3) == 0)
			data->tex.we.path = &line[3];
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
		line = get_next_line(fd, 0);
	}
	cub3d_map_init(data, line);
	cub3d_fill_map(data, line, data->map, 0);
	cub3d_map_end(data, line, fd);
	return (EXIT_SUCCESS);
}
