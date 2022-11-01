/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/29 14:19:58 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_get_tex_path(t_data *data, char *line, int fd)
{
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
			cub3d_separate_colours(data, line, 0);
		else if (ft_strncmp("C", line, 1) == 0)
			cub3d_separate_colours(data, line, 1);
		free(line);
		line = get_next_line(fd, 0);
	}
}
