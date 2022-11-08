/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:28 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/08 12:08:01 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	cub3d_destroyer_helper(t_data *data);

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
	{
		cub3d_destroyer_helper(data);
	}
	if (data != NULL)
		free(data);
	if (exit_status == EXIT_SUCCESS)
		exit(exit_status);
	else
		return (exit_status);
}

static void	cub3d_destroyer_helper(t_data *data)
{
	matrix_cleanup(data->map);
	free(data->tex.no.path);
	free(data->tex.so.path);
	free(data->tex.we.path);
	free(data->tex.ea.path);
}
