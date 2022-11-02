/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/02 11:31:57 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
		else if (ft_strncmp("F", &line[2], 1) == 0)
			cub3d_set_colours(data, line, 0);
		else if (ft_strncmp("C", &line[2], 1) == 0)
		{
			cub3d_set_colours(data, line, 1);
			flag = 1;
		}
		else if (ft_strncmp("\n", line, 1) != 0 && flag == 1)
		{
			free(line);
			break;
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	return (EXIT_SUCCESS);
}
