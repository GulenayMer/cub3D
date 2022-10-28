/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:51 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/25 15:30:17 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_draw_image(void *input)
{
	t_data	*data;

	data = (t_data *)input;
	ft_bzero(data->image.addr, (WIDTH * HEIGHT) * sizeof(int));
	cub3d_raycast(data);
	cub3d_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (EXIT_SUCCESS);
}
