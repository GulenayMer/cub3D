/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:49 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/21 13:19:15 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	cub3d_raycast_pos_def(t_data *data, int x);
static void	cub3d_raycast_side_def(t_data *data);
static void	cub3d_raycast_dda(t_data *data);
static void	cub3d_raycast_draw_def(t_data *data);

int	cub3d_raycast(t_data *data)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		cub3d_raycast_pos_def(data, x);
		cub3d_raycast_side_def(data);
		cub3d_raycast_dda(data);
		cub3d_raycast_draw_def(data);
		cub3d_calculate_wallx(data);
		cub3d_draw_line(data, x, data->draw);
		x += 1;
	}
	cub3d_check_fps(data);
	return (EXIT_SUCCESS);
}

void	cub3d_raycast_pos_def(t_data *data, int x)
{
	data->camera_x = 2 * x / (double) WIDTH - 1;
	data->ray.pos.x = data->direction.x + data->plane.x * data->camera_x;
	data->ray.pos.y = data->direction.y + data->plane.y * data->camera_x;
	data->ray.map.x = (int) data->player.x;
	data->ray.map.y = (int) data->player.y;
	if (data->ray.pos.x == 0)
		data->ray.delta.x = 1e30;
	else
		data->ray.delta.x = fabs(1 / data->ray.pos.x);
	if (data->ray.pos.y == 0)
		data->ray.delta.y = 1e30;
	else
		data->ray.delta.y = fabs(1 / data->ray.pos.y);
}

void	cub3d_raycast_side_def(t_data *data)
{
	if (data->ray.pos.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.x - data->ray.map.x)
			* data->ray.delta.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.map.x + 1.0 - data->player.x)
			* data->ray.delta.x;
	}
	if (data->ray.pos.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.y - data->ray.map.y)
			* data->ray.delta.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.map.y + 1.0 - data->player.y)
			* data->ray.delta.y;
	}
}

void	cub3d_raycast_dda(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta.x;
			data->ray.map.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta.y;
			data->ray.map.y += data->ray.step.y;
			data->ray.side = 1;
		}
		if (cub3d_check_square(data, (int) data->ray.map.x,
				(int) data->ray.map.y) > 0)
			data->ray.hit = 1;
	}
}

void	cub3d_raycast_draw_def(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_dist = (data->ray.side_dist.x - data->ray.delta.x);
	else
		data->ray.wall_dist = (data->ray.side_dist.y - data->ray.delta.y);
	data->draw.line_height = (int)(HEIGHT / data->ray.wall_dist);
	data->draw.start = -data->draw.line_height / 2 + HEIGHT / 2;
	if (data->draw.start < 0)
		data->draw.start = 0;
	data->draw.end = data->draw.line_height / 2 + HEIGHT / 2;
	if (data->draw.end >= HEIGHT)
		data->draw.end = HEIGHT -1;
	data->draw.hex_colour = RED3;
	if (data->ray.side == 1)
		data->draw.hex_colour = RED1;
}
