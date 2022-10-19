/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:49 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/19 16:06:54 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_check_square(t_data *data, t_coord map)
{
	int		ret;
	t_cell	*cell;

	cell = (t_cell *) matrix_get(data->map, map.x, map.y);
	ret = cell->type;
	return (ret);
}

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
		data->direction.y = (double) - 1;
		return (EXIT_SUCCESS);
	}
	else if (cell->type == TYPE_S)
	{
		data->direction.x = (double) 0;
		data->direction.y = (double) 1;
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
		data->direction.x = (double) - 1;
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
		data->plane.x = 0;
		data->plane.y = -0.66;
		return ;
	}
	else if (data->direction.y == 1)
	{
		data->plane.x = 0;
		data->plane.y = 0.66;
		return ;
	}
	else if (data->direction.x == 1)
	{
		data->plane.x = 0.66;
		data->plane.y = 0;
		return ;
	}
	else if (data->direction.x == -1)
	{
		data->plane.x = -0.66;
		data->plane.y = 0;
		return ;
	}
}

void	cub3d_draw_line(t_data *data, int col, t_draw draw)
{
	int	y;

	y = draw.start;
	while (y <= draw.end)
	{
		cub3d_mlx_pixel_put(data, col, y, draw.hex_colour);
		y += 1;
	}
}

int	cub3d_raycast(void *input)
{
	t_data	*data;
	int		x;

	x = 0;
	data = (t_data *) input;
	cub3d_find_player(data);
	cub3d_init_direction(data);
	cub3d_init_plane(data);
	while (x < WIDTH)
	{
		// First Part 
		data->camera_x = 2 * x / (double) data->xlen - 1;
		data->ray.pos.x = data->direction.x + data->plane.x * data->camera_x;
		data->ray.pos.y = data->direction.y + data->plane.y * data->camera_x;
		data->ray.delta.x = fabs(1 / data->ray.pos.x);
		data->ray.delta.y = fabs(1 / data->ray.pos.y);
		// Second Part
		if (data->ray.pos.x < 0)
		{
			data->ray.step.x = -1;
			data->ray.side_dist.x = (data->ray.pos.x - data->ray.map.x) * data->ray.delta.x;
		}
		else
		{
			data->ray.step.x = 1;
			data->ray.side_dist.x = (data->ray.map.x + 1.0 - data->ray.pos.x) * data->ray.delta.x;
		}
		if (data->ray.pos.y < 0)
		{
			data->ray.step.y = -1;
			data->ray.side_dist.y = (data->ray.pos.y - data->ray.map.y) * data->ray.delta.y;
		}
		else
		{
			data->ray.step.y = 1;
			data->ray.side_dist.y = (data->ray.map.y + 1.0 - data->ray.pos.y) * data->ray.delta.y;
		}
		// Third Part: DDA
		while (data->ray.hit == 0)
		{
			if (data->ray.side_dist.x < data->ray.side_dist.y)
        	{
				data->ray.side_dist.x += data->ray.delta.y;
				data->ray.map.x += data->ray.step.x;
				data->ray.side = 0;
			}
        	else
			{
				data->ray.side_dist.y += data->ray.delta.y;
				data->ray.map.y += data->ray.step.y;
				data->ray.side = 1;
			}
        	if (cub3d_check_square(data, data->ray.map) > 0)
				data->ray.hit = 1;
      	} 
		// Fourth Part
		if(data->ray.side == 0) 
			data->ray.wall_dist = (data->ray.side_dist.x - data->ray.delta.x);
      	else
			data->ray.wall_dist = (data->ray.side_dist.y - data->ray.delta.y);
		// Fifth Part
		data->draw.line_height = (int)(HEIGHT / data->ray.wall_dist);
		data->draw.start = -data->draw.line_height / 2 + HEIGHT / 2;
		if (data->draw.start < 0)
			data->draw.start = 0;
		data->draw.end = data->draw.line_height / 2 + HEIGHT / 2;
		if (data->draw.end >= HEIGHT)
			data->draw.end = HEIGHT -1;
		// Sixth Part
		if (data->ray.side == 1)
			data->draw.hex_colour = RED3;
		else
			data->draw.hex_colour = RED3 / 2;
		// Seventh Part: Draw
		cub3d_draw_line(data, x, data->draw);
		// Eight Part: FPS
		data->fps.old_time = data->fps.cur_time;
		data->fps.cur_time
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (EXIT_SUCCESS);
}

