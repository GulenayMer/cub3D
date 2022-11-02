/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:12:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/30 20:58:02 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->count_y)
	{
		x = 0;
		while (x < data->xlen)
		{
			if (check_walls(data, x, y))
				return (EXIT_FAILURE);
			if (check_spaces(data, x, y))
				return (EXIT_FAILURE);
			x += 1;
		}
		y += 1;
	}
	return (EXIT_SUCCESS);
}
