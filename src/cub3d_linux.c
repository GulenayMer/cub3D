/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:28 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 15:20:40 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_destroyer(t_data *data, int exit_status)
{
	if (exit_status == EXIT_SUCCESS)
	{
		mlx_destroy_image(data->mlx, data->image.img);
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
