/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:05:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/25 12:30:15 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	cub3d_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
}

void	cub3d_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length
			+ x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	cub3d_mlx_mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x < data->ctr_x)
	{
		mlx_mouse_move(data->mlx, data->win, data->mouse.x,
			data->mouse.y);
		cub3d_rotate_left(data, data->fps.rotate_speed / 2);
		data->ctr_x = x;
	}
	if (x > data->ctr_x)
	{
		mlx_mouse_move(data->mlx, data->win, data->mouse.x,
			data->mouse.y);
		cub3d_rotate_right(data, data->fps.rotate_speed / 2);
		data->ctr_x = x;
	}
	return (EXIT_SUCCESS);
}
