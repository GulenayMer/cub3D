/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:07:12 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/02 14:47:03 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_top_wall(t_data *data, int x, int y);
static int	check_bottom_wall(t_data *data, int x, int y);
static int	check_left_wall(t_data *data, int x, int y);
static int	check_right_wall(t_data *data, int x, int y);

/* we pass the postion inside the map-- if we are at the floor,
	need to check if it is surrounded by walls
	no space is accepted! */
int	check_walls(t_data *data, int x, int y)
{
	if (cub3d_check_square(data, x, y) == TYPE_FLOOR)
	{
		if (check_top_wall(data, x, y) || check_bottom_wall(data, x, y) \
			|| check_left_wall(data, x, y) || check_right_wall(data, x, y))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_top_wall(t_data *data, int x, int y)
{
	while (y > 0)
	{
		y -= 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Error, floor must be surronded by the walls!\n", 2);
	return (EXIT_FAILURE);
}

static int	check_bottom_wall(t_data *data, int x, int y)
{
	while (y < data->map->count_y)
	{
		y += 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Error, floor must be surronded by the walls!\n", 2);
	return (EXIT_FAILURE);
}

int	check_left_wall(t_data *data, int x, int y)
{
	while (x > 0)
	{
		x -= 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Error, floor must be surronded by the walls!\n", 2);
	return (EXIT_FAILURE);
}

int	check_right_wall(t_data *data, int x, int y)
{
	while (x < data->xlen - 1)
	{
		x += 1;
		if (cub3d_check_square(data, x, y) == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Error, floor must be surronded by the walls!\n", 2);
	return (EXIT_FAILURE);
}
