/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:50:43 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/04 11:55:01 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	cub3d_draw_minimap_helper(int tile, int colour);

void	cub3d_draw_minimap(t_data *data, int tile, int offset_x,
		int offset_y)
{
	int	x;
	int	y;
	int	colour;

	x = 0;
	y = 0;
	colour = 0;
	colour = cub3d_draw_minimap_helper(tile, colour);
	while (y < data->minimap.unit.y)
	{
		while (x < data->minimap.unit.x)
		{
			cub3d_mlx_pixel_put(data, data->minimap.iter.x,
				data->minimap.iter.y, colour);
			x += 1;
			data->minimap.iter.x += 1;
		}
		data->minimap.iter.x = offset_x;
		data->minimap.iter.y += 1;
		y += 1;
		x = 0;
	}
	data->minimap.iter.y = offset_y;
}

static int	cub3d_draw_minimap_helper(int tile, int colour)
{
	if (tile == 0)
		colour = BLACK;
	else if (tile == 1)
		colour = WHITE;
	else if (tile == -1)
		colour = RED;
	return (colour);
}

void	cub3d_draw_player(t_data *data)
{
	int	x;
	int	y;

	data->minimap.p_unit.x = data->minimap.unit.x / 3;
	data->minimap.p_unit.y = data->minimap.unit.y / 3;
	data->minimap.p_size.x = data->minimap.unit.x * data->player.x
		+ (WIDTH - data->minimap.size.x) - 25;
	data->minimap.p_size.y = (data->minimap.unit.y * data->player.y)
		+ Y_OFFSET + 5;
	x = data->minimap.p_size.x - data->minimap.p_unit.x;
	y = data->minimap.p_size.y - data->minimap.p_unit.y;
	while (y < data->minimap.p_size.y)
	{
		while (x < data->minimap.p_size.x)
		{
			cub3d_mlx_pixel_put(data, x, y, RED);
			x += 1;
		}
		x = data->minimap.p_size.x - data->minimap.p_unit.x;
		y += 1;
	}
}
