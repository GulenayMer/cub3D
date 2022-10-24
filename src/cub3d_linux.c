/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:28 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/24 15:50:56 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_destroyer(t_data *data, int exit_status)
{
	if (exit_status == EXIT_SUCCESS)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		mlx_destroy_image(data->mlx, data->tex.no.img);
		mlx_destroy_image(data->mlx, data->tex.so.img);
		mlx_destroy_image(data->mlx, data->tex.ea.img);
		mlx_destroy_image(data->mlx, data->tex.we.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		if (data->mlx != NULL)
			free(data->mlx);
	}
	if (data != NULL)
		matrix_cleanup(data->map);
	if (data != NULL)
		free(data);
	if (exit_status == EXIT_SUCCESS)
		exit(exit_status);
	else
		return (exit_status);
}
