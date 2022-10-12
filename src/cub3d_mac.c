/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:25 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/12 21:06:43 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	fdf_destroyer(t_data *data, int exit_status)
{
	if (exit_status == EXIT_SUCCESS)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		if (data->mlx != NULL)
			free(data->mlx);
	}
	if (data->map != NULL)
		matrix_cleanup(data->map);
	if (data != NULL)
		free(data);
	if (exit_status == EXIT_SUCCESS)
		exit(exit_status);
	else
		return (exit_status);
}
