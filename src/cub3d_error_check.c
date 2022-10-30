/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:07:12 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/30 12:46:09 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* count rows included SO, WE, NO, EA, F, C */

int count_map_rows(t_data *data)
{
	char	*line;
	int		line_count;

	line = get_next_line(data->mapfd);
	line_count = 0;
	while (line != NULL)
	{
	
		line_count++;
		free(line);
		line = get_next_line(mapfd);

	}
	close(mapfd);
	return (line_count);

}