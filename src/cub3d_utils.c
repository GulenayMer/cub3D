/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:20:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/21 12:41:49 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		t_ms;

	gettimeofday(&time, NULL);
	t_ms = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (t_ms);
}

void	cub3d_draw_line(t_data *data, int col, t_draw draw)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < draw.start)
			cub3d_mlx_pixel_put(data, col, y, 0xAAFFAA);
		else if (y > draw.end)
			cub3d_mlx_pixel_put(data, col, y, 0xAAAAFF);
		/* else if (y >= draw.start && y <= draw.end)
			cub3d_mlx_pixel_put(data, col, y, draw.hex_colour);
		else
			cub3d_mlx_pixel_put(data, col, y, 0xAAAAFF); */
		y += 1;
	}
}

int	cub3d_check_square(t_data *data, int x, int y)
{
	int		ret;
	t_cell	*cell;

	ret = -1;
	cell = (t_cell *)matrix_get(data->map, x, y);
	if (cell != NULL)
		ret = cell->type;
	return (ret);
}

void	cub3d_check_fps(t_data *data)
{
	data->fps.old_time = data->fps.cur_time;
	data->fps.cur_time = get_time();
	data->fps.frame_time = (data->fps.cur_time - data->fps.old_time) / 1000.0;
	printf("FPS: %f\n", 1.0 / data->fps.frame_time);
	data->fps.move_speed = data->fps.frame_time * 5.0;
	data->fps.rotate_speed = data->fps.frame_time * 3.0;
}

void	cub3d_texture_init(t_data *data, int col)
{
	int	block;
	int	y;

	block = TEX_SIZE;
	data->tex.no.img = mlx_xpm_file_to_image(data->mlx, NORTH, &block, &block);
	data->tex.so.img = mlx_xpm_file_to_image(data->mlx, SOUTH, &block, &block);
	data->tex.ea.img = mlx_xpm_file_to_image(data->mlx, EAST, &block, &block);
	data->tex.we.img = mlx_xpm_file_to_image(data->mlx, WEST, &block, &block);
	// CONTROLL FOR NULL
	data->tex.no.addr = (int *)mlx_get_data_addr(
			data->tex.no.img,
			&data->tex.no.bits_per_pixel,
			&data->tex.no.line_length,
			&data->tex.no.endian);
	data->tex.so.addr = (int *)mlx_get_data_addr(
			data->tex.so.img,
			&data->tex.so.bits_per_pixel,
			&data->tex.so.line_length,
			&data->tex.so.endian);
	data->tex.ea.addr = (int *)mlx_get_data_addr(
			data->tex.ea.img,
			&data->tex.ea.bits_per_pixel,
			&data->tex.ea.line_length,
			&data->tex.ea.endian);
	data->tex.we.addr = (int *)mlx_get_data_addr(
			data->tex.we.img,
			&data->tex.we.bits_per_pixel,
			&data->tex.we.line_length,
			&data->tex.we.endian);
	// Calculate value of WALLX
	if (data->ray.side == 0)
		data->tex.wall_x = (int) data->player.y
			+ data->ray.wall_dist * data->ray.pos.y;
	else
		data->tex.wall_x = (int) data->player.x
			+ data->ray.wall_dist * data->ray.pos.x;
	data->tex.wall_x -= floor(data->tex.wall_x);
	data->tex.coord.x = (int)(data->tex.wall_x * (2 * TEX_SIZE));
	if (data->ray.side == 0 && data->ray.pos.x > 0)
		data->tex.coord.x = TEX_SIZE - data->tex.coord.x - 1;
	if (data->ray.side == 1 && data->ray.pos.y < 0)
		data->tex.coord.x = TEX_SIZE - data->tex.coord.x - 1;
	
	//Calculate texture coord increse
	data->tex.step = 1.0 * TEX_SIZE * data->draw.line_height;
	data->tex.tex_pos = (data->draw.start - HEIGHT
			/ 2 + data->draw.line_height / 2) * data->tex.step;
	y = data->draw.start;
	while (y <= data->draw.end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		data->tex.coord.y = (int)data->tex.tex_pos & (TEX_SIZE - 1);
		data->tex.tex_pos += data->tex.step;
		if (data->ray.side == 1)
		{
			if (data->ray.pos.y > 0)
			{
				data->tex.colour = data->tex.so.addr
				[TEX_SIZE * data->tex.coord.y + data->tex.coord.x];
			}
			else
			{
				data->tex.colour = data->tex.no.addr
				[TEX_SIZE * data->tex.coord.y + data->tex.coord.x];
			}
		}
		else
		{
			if (data->ray.pos.x < 0)
			{
				data->tex.colour = data->tex.we.addr
				[TEX_SIZE * data->tex.coord.y + data->tex.coord.x];
			}
			else
			{
				data->tex.colour = data->tex.ea.addr
				[TEX_SIZE * data->tex.coord.y + data->tex.coord.x];
			}
		}
		cub3d_mlx_pixel_put(data, col, y, data->tex.colour);
		y += 1;
	}
}
