/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:05:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 10:06:11 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	cub3d_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img,
			&data->image->bits_per_pixel,
			&data->image->line_length,
			&data->image->endian);
}

void	cub3d_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length
			+ x * (data->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
