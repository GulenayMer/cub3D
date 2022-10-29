/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:18:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/28 16:46:00 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	cub3d_find_player(t_data *data)
{
	t_coord	coord;
	t_cell	*cell;

	coord.y = 0;
	while (coord.y < data->map->count_y - 1)
	{
		coord.x = 0;
		while (coord.x < data->map->count_x - 1)
		{
			cell = (t_cell *)matrix_get(data->map, coord.x, coord.y);
			if (cell->type == TYPE_N
				|| cell->type == TYPE_S
				|| cell->type == TYPE_E
				|| cell->type == TYPE_W)
			{
				data->player.x = (double) coord.x;
				data->player.y = (double) coord.y;
				return ;
			}
			coord.x += 1;
		}
		coord.y += 1;
	}	
}

void	cub3d_direction_set(t_data *data, char cell)
{
	if (cell == 'N')
	{
		data->direction.x = (double) 0;
		data->direction.y = (double) -1;
		return ;
	}
	else if (cell == 'S')
	{
		data->direction.x = (double) 0;
		data->direction.y = (double) 1;
		return ;
	}
	else if (cell == 'E')
	{
		data->direction.x = (double) 1;
		data->direction.y = (double) 0;
		return ;
	}
	else if (cell == 'W')
	{
		data->direction.x = (double) -1;
		data->direction.y = (double) 0;
		return ;
	}
}

void	cub3d_init_dir_plane(t_data *data, t_coord coord, char cell)
{
	data->player.x = (double) coord.x;
	data->player.y = (double) coord.y;
	cub3d_direction_set(data, cell);
	cub3d_init_plane(data, cell);
	return ;
}

void	cub3d_init_plane(t_data *data, char cell)
{
	if (cell == 'N')
	{
		data->plane.x = 1;
		data->plane.y = 0;
		return ;
	}
	if (cell == 'S')
	{
		data->plane.x = -1;
		data->plane.y = 0;
		return ;
	}
	if (cell == 'E')
	{
		data->plane.x = 0;
		data->plane.y = 1;
		return ;
	}
	if (cell == 'W')
	{
		data->plane.x = 0;
		data->plane.y = -1;
		return ;
	}
}
