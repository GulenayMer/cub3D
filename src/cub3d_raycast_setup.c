/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:18:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/19 18:17:58 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	cub3d_find_player(t_data *data)
{
	t_coord	coord;
	t_cell	*cell;

	coord.y = 0;
	while (coord.y < data->map->count_y)
	{
		coord.x = 0;
		while (coord.x < data->map->count_x)
		{
			cell = (t_cell *)matrix_get(data->map, coord.x, coord.y);
			if (cell->type == TYPE_N
				|| cell->type == TYPE_S
				|| cell->type == TYPE_E
				|| cell->type == TYPE_W)
			{
				data->player.x = (double) coord.x;
				data->player.y = (double) coord.y;
				data->ray.map.x = coord.x;
				data->ray.map.y = coord.y;
				return ;
			}
			coord.x += 1;
		}
		coord.y += 1;
	}	
}

int	cub3d_direction_set(t_data *data, t_cell *cell)
{
	if (cell->type == TYPE_N)
	{
		data->direction.x = (double) 0;
		data->direction.y = (double) 1;
		return (EXIT_SUCCESS);
	}
	else if (cell->type == TYPE_S)
	{
		data->direction.x = (double) 0;
		data->direction.y = (double) -1;
		return (EXIT_SUCCESS);
	}
	else if (cell->type == TYPE_E)
	{
		data->direction.x = (double) 1;
		data->direction.y = (double) 0;
		return (EXIT_SUCCESS);
	}
	else if (cell->type == TYPE_W)
	{
		data->direction.x = (double) -1;
		data->direction.y = (double) 0;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	cub3d_init_direction(t_data *data)
{
	t_coord		coord;
	t_cell		*cell;

	coord.y = 0;
	while (coord.y < data->map->count_y)
	{
		coord.x = 0;
		while (coord.x < data->map->count_x)
		{
			cell = (t_cell *)matrix_get(data->map, coord.x, coord.y);
			if (cub3d_direction_set(data, cell) == EXIT_SUCCESS)
				return ;
			coord.x += 1;
		}
		coord.y += 1;
	}	
}

void	cub3d_init_plane(t_data *data)
{
	if (data->direction.y == -1)
	{
		data->plane.x = -0.66;
		data->plane.y = 0;
		return ;
	}
	else if (data->direction.y == 1)
	{
		data->plane.x = 0.66;
		data->plane.y = 0;
		return ;
	}
	else if (data->direction.x == 1)
	{
		data->plane.x = 0;
		data->plane.y = -0.66;
		return ;
	}
	else if (data->direction.x == -1)
	{
		data->plane.x = 0;
		data->plane.y = 0.66;
		return ;
	}
}
