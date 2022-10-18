/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:25:04 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/06 11:01:50 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/* check if the first line is filled with 1s or spaces */
int	check_first_line(t_cell *cell, t_data *data, int x, int y)
{
	while (x < data->xlen && y == 0)
	{
		if (cell->line[x] != '1')
			return (1);
		x++;
	}
	return (0);
}

/* check if the last line is filled with 1s */
/* int	check_last_line(t_solong *game)
{
	int	i;
	int	j;

	j = game->map_height - 1;
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[j][i] != '1')
			return (error_message(3));
		i++;
	}
	return (0);
}
 */