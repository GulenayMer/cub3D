/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:51 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/20 15:08:42 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_draw_image(void *input)
{
	t_data	*data;

	data = (t_data *)input;
	ft_bzero(data->image.addr, (WIDTH * HEIGHT) * sizeof(int));
	cub3d_raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (EXIT_SUCCESS);
}
