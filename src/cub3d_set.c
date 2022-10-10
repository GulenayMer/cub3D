/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:51 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/10 13:06:52 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_draw_image(void *input)
{
	int		x;
	int		y;
	t_data	*data;

	data = (t_data*) input;
	y = 0;
	ft_bzero(data->addr, (WIDTH * HEIGHT) * sizeof(int));
	//fdf_set_coordinates(fdf);
	while (y < data->map->count_y)
	{
		x = 0;
		while (x < data->map->count_x)
		{
			//fdf_draw_lines(fdf, x, y);
			cub3d_mlx_pixel_put(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}