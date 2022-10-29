/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:47 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/28 16:53:12 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	cub3d_move_fb(int key, t_data *data);
static void	cub3d_move_ss(int key, t_data *data);

int	cub3d_key_press(int key, t_data *data)
{
	if (key == ESC_KEY)
		cub3d_close_win(data);
	if (key == A_KEY)
		cub3d_move_ss(A_KEY, data);
	if (key == D_KEY)
		cub3d_move_ss(D_KEY, data);
	if (key == W_KEY || key == UP)
		cub3d_move_fb(W_KEY, data);
	if (key == S_KEY || key == DOWN)
		cub3d_move_fb(S_KEY, data);
	if (key == Q_KEY || key == LEFT)
		cub3d_rotate_left(data, data->fps.rotate_speed);
	if (key == E_KEY || key == RIGHT)
		cub3d_rotate_right(data, data->fps.rotate_speed);
	return (0);
}

static void	cub3d_move_fb(int key, t_data *data)
{
	if (key == W_KEY || key == UP)
	{
		if (cub3d_check_square(data,
				(int)(data->player.x + data->direction.x
				* data->fps.move_speed), (int)data->player.y) == TYPE_FLOOR)
			data->player.x += data->direction.x * data->fps.move_speed;
		if (cub3d_check_square(data,
				(int)(data->player.x), (int)(data->player.y + data->direction.y
			* data->fps.move_speed)) == TYPE_FLOOR)
			data->player.y += data->direction.y * data->fps.move_speed;
	}
	if (key == S_KEY || key == DOWN)
	{
		if (cub3d_check_square(data,
				(int)(data->player.x - data->direction.x
				* data->fps.move_speed), (int)data->player.y) == TYPE_FLOOR)
			data->player.x -= data->direction.x * data->fps.move_speed;
		if (cub3d_check_square(data,
				(int)(data->player.x), (int)(data->player.y - data->direction.y
			* data->fps.move_speed)) == TYPE_FLOOR)
			data->player.y -= data->direction.y * data->fps.move_speed;
	}
}

static void	cub3d_move_ss(int key, t_data *data)
{
	if (key == D_KEY)
	{
		if (cub3d_check_square(data,
				(int)(data->player.x + (-data->direction.y
					* data->fps.move_speed)), (int)data->player.y)
					== TYPE_FLOOR)
			data->player.x += -data->direction.y * data->fps.move_speed;
		if (cub3d_check_square(data,
				(int)(data->player.x), (int)(data->player.y + data->direction.x
			* data->fps.move_speed)) == TYPE_FLOOR)
			data->player.y += data->direction.x * data->fps.move_speed;
	}
	if (key == A_KEY)
	{
		if (cub3d_check_square(data,
				(int)(data->player.x - (-data->direction.y
					* data->fps.move_speed)), (int)data->player.y)
					== TYPE_FLOOR)
			data->player.x -= -data->direction.y * data->fps.move_speed;
		if (cub3d_check_square(data,
				(int)(data->player.x), (int)(data->player.y - data->direction.x
			* data->fps.move_speed)) == TYPE_FLOOR)
			data->player.y -= data->direction.x * data->fps.move_speed;
	}
}

void	cub3d_rotate_left(t_data *data, double rotate_speed)
{
	data->old_dir.x = data->direction.x;
	data->direction.x = data->direction.x * cos(-rotate_speed)
		- data->direction.y * sin(-rotate_speed);
	data->direction.y = data->old_dir.x * sin(-rotate_speed)
		+ data->direction.y * cos(-rotate_speed);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos(-rotate_speed)
		- data->plane.y * sin(-rotate_speed);
	data->plane.y = data->old_plane.x * sin(-rotate_speed)
		+ data->plane.y * cos(-rotate_speed);
}

void	cub3d_rotate_right(t_data *data, double rotate_speed)
{
	data->old_dir.x = data->direction.x;
	data->direction.x = data->direction.x * cos(rotate_speed)
		- data->direction.y * sin(rotate_speed);
	data->direction.y = data->old_dir.x * sin(rotate_speed)
		+ data->direction.y * cos(rotate_speed);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos(rotate_speed)
		- data->plane.y * sin(rotate_speed);
	data->plane.y = data->old_plane.x * sin(rotate_speed)
		+ data->plane.y * cos(rotate_speed);
}
