/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:51 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 17:43:17 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_draw_image(void *input)
{
	t_data	*data;
	void	*old;

	data = (t_data *)input;
	old = data->image.img;
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
	cub3d_raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	mlx_destroy_image(data->mlx, old);
	return (EXIT_SUCCESS);
}
