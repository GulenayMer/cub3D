/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:20:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/20 15:14:09 by mgulenay         ###   ########.fr       */
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
		else if (y >= draw.start && y <= draw.end)
			cub3d_mlx_pixel_put(data, col, y, draw.hex_colour);
		else
			cub3d_mlx_pixel_put(data, col, y, 0xAAAAFF);
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
