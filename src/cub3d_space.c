/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:25:04 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/30 20:57:32 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_top(t_data *data, int x, int y);
static int	check_bottom(t_data *data, int x, int y);
static int	check_left(t_data *data, int x, int y);
static int	check_right(t_data *data, int x, int y);

int	check_spaces(t_data *data, int x, int y)
{
	if (cub3d_check_square(data, x, y) == TYPE_NOTHING)
	{
		if (check_top(data, x, y) || check_bottom(data, x, y) \
			|| check_left(data, x, y) || check_right(data, x, y))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_top(t_data *data, int x, int y)
{
	while (y > 0)
	{
		y -= 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
		if (cub3d_check_square(data, x, y) == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_bottom(t_data *data, int x, int y)
{
	while (y < data->map->count_y)
	{
		y += 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
		if (cub3d_check_square(data, x, y) == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_left(t_data *data, int x, int y)
{
	while (x > 0)
	{
		x -= 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
		if (cub3d_check_square(data, x, y) == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_right(t_data *data, int x, int y)
{
	while (x < data->xlen)
	{
		x += 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
		if (cub3d_check_square(data, x, y) == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
