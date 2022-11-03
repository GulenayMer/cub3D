/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:25:04 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/03 11:41:36 by mgulenay         ###   ########.fr       */
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
	int	type;

	while (y >= 0)
	{
		y -= 1;
		if (y < 0)
			y = 0;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_NOTHING)
			return (EXIT_SUCCESS);
		if (type == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_bottom(t_data *data, int x, int y)
{
	int	type;

	while (y < data->map->count_y)
	{
		y += 1;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_NOTHING)
			return (EXIT_SUCCESS);
		if (type == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_left(t_data *data, int x, int y)
{
	int	type;

	while (x >= 0)
	{
		x -= 1;
		if (x < 0)
			x = 0;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_NOTHING)
			return (EXIT_SUCCESS);
		if (type == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_right(t_data *data, int x, int y)
{
	int	type;

	while (cub3d_check_square(data, x, y) != TYPE_NEWLINE)
	{
		x += 1;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_NOTHING)
			return (EXIT_SUCCESS);
		if (type == TYPE_FLOOR)
		{
			ft_putstr_fd("Error, empty spaces inside the map!\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
