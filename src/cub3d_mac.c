/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:25 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/07 13:35:57 by mgulenay         ###   ########.fr       */
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
		if (data->mlx != NULL)
			free(data->mlx);
	}
	if (data != NULL)
	{
		if (data->map != NULL)
			matrix_cleanup(data->map);
	}
	if (data != NULL)
		free(data);
	if (exit_status == EXIT_SUCCESS)
		exit(exit_status);
	else
		return (exit_status);
}
