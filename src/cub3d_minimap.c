/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:27:38 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/08 11:59:38 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static t_coord	cub3d_minimap_unit_size(t_data *data);
static void		cub3d_minimap_setup(t_data *data);

void	cub3d_minimap(t_data *data)
{
	cub3d_minimap_setup(data);
	while (data->minimap.map.y < data->map->count_y)
	{
		while (cub3d_check_square(data, data->minimap.map.x,
				data->minimap.map.y) < TYPE_NEWLINE && cub3d_check_square(
				data, data->minimap.map.x, data->minimap.map.y) >= TYPE_NOTHING)
		{	
			if (cub3d_check_square(
					data, data->minimap.map.x, data->minimap.map.y)
				> TYPE_FLOOR)
				cub3d_draw_minimap(data, 1, data->minimap.iter.x,
					data->minimap.iter.y);
			else if (cub3d_check_square
				(data, data->minimap.map.x, data->minimap.map.y) == TYPE_FLOOR)
				cub3d_draw_minimap(data, 0, data->minimap.iter.x,
					data->minimap.iter.y);
			data->minimap.map.x += 1;
			data->minimap.iter.x += data->minimap.unit.x;
		}
		data->minimap.map.x = 0;
		data->minimap.map.y += 1;
		data->minimap.iter.x = X_OFFSET - 30 - data->minimap.size.x;
		data->minimap.iter.y += data->minimap.unit.y;
	}
	cub3d_draw_player(data);
}

static t_coord	cub3d_minimap_unit_size(t_data *data)
{
	t_coord	minimap;

	minimap.x = (WIDTH / 7) / data->map->count_x - 1;
	minimap.y = (HEIGHT / 7) / data->map->count_y - 1;
	if (data->map->count_x < data->map->count_y)
		minimap.y = minimap.x;
	else
		minimap.x = minimap.y;
	return (minimap);
}

static void	cub3d_minimap_setup(t_data *data)
{
	data->minimap.unit = cub3d_minimap_unit_size(data);
	data->minimap.size.x = data->minimap.unit.x * data->map->count_x - 1;
	data->minimap.size.y = data->minimap.unit.y * data->map->count_y - 1;
	data->minimap.map.x = 0;
	data->minimap.map.y = 0;
	data->minimap.iter.x = X_OFFSET - 30 - data->minimap.size.x;
	data->minimap.iter.y = Y_OFFSET;
}
