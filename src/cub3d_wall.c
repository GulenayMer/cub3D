/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:07:12 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/07 17:39:38 by mgulenay         ###   ########.fr       */
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
	int	type;

	type = cub3d_check_square(data, x, y);
	if (type == TYPE_FLOOR)
	{
		if (check_top_wall(data, x, y) || check_bottom_wall(data, x, y) \
			|| check_left_wall(data, x, y) || check_right_wall(data, x, y))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_top_wall(t_data *data, int x, int y)
{
	int	type;
	int	check;

	type = cub3d_check_square(data, x, y);
	if (y == 0 && type == TYPE_FLOOR)
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	else if (y == 0)
		return (EXIT_SUCCESS);
	check = cub3d_check_square(data, x, y - 1);
	if (type == TYPE_FLOOR && (check != TYPE_WALL && check != TYPE_FLOOR))
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_bottom_wall(t_data *data, int x, int y)
{
	int	type;
	int	check;

	type = cub3d_check_square(data, x, y);
	if (y == data->map->count_y - 1 && type == TYPE_FLOOR)
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	else if (y == data->map->count_y - 1)
		return (EXIT_SUCCESS);
	check = cub3d_check_square(data, x, y + 1);
	if (type == TYPE_FLOOR && (check != TYPE_WALL && check != TYPE_FLOOR))
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_left_wall(t_data *data, int x, int y)
{
	int	type;
	int	check;

	type = cub3d_check_square(data, x, y);
	if (x == 0 && type == TYPE_FLOOR)
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	else if (x == 0)
		return (EXIT_SUCCESS);
	check = cub3d_check_square(data, x - 1, y);
	if (type == TYPE_FLOOR && (check != TYPE_WALL && check != TYPE_FLOOR))
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_right_wall(t_data *data, int x, int y)
{
	int	type;
	int	check;

	type = cub3d_check_square(data, x, y);
	check = cub3d_check_square(data, x + 1, y);
	if (type == TYPE_FLOOR && (check != TYPE_WALL && check != TYPE_FLOOR))
	{
		ft_printf(STDERR_FILENO, WALL_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/* 
static int	check_top_wall(t_data *data, int x, int y)
{
	int	type;
	int	flag;

	flag = 0;
	while (y >= 0)
	{
		y -= 1;
		if (y < 0 && flag == 0)
		{
			y = 0;
			flag = 1;
		}
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_NEWLINE)
			return (EXIT_SUCCESS);
	}
	ft_printf(STDERR_FILENO, WALL_ERR);
	return (EXIT_FAILURE);
}

static int	check_bottom_wall(t_data *data, int x, int y)
{
	int	type;

	while (y < data->map->count_y)
	{
		y += 1;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL || type == TYPE_END)
			return (EXIT_SUCCESS);
	}
	ft_printf(STDERR_FILENO, WALL_ERR);
	return (EXIT_FAILURE);
}

int	check_left_wall(t_data *data, int x, int y)
{
	int	type;
	int	flag;

	flag = 0;
	while (x >= 0)
	{
		x -= 1;
		if (x < 0 && flag == 0)
		{
			flag = 1;
			x = 0;
		}
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_printf(STDERR_FILENO, WALL_ERR);
	return (EXIT_FAILURE);
}

int	check_right_wall(t_data *data, int x, int y)
{
	int	type;
	int	check;

	while (cub3d_check_square(data, x, y) != TYPE_NEWLINE)
	{
		x += 1;
		type = cub3d_check_square(data, x, y);
		if (type == TYPE_FLOOR)
		{
			check = cub3d_check_square(data, x + 1, y);
			if (check == TYPE_NEWLINE)
			{
				ft_printf(STDERR_FILENO, WALL_ERR);
				return (EXIT_FAILURE);
			}
		}
		if (type == TYPE_NEWLINE)
			return (EXIT_SUCCESS);
		if (type == TYPE_WALL)
			return (EXIT_SUCCESS);
	}
	ft_printf(STDERR_FILENO, WALL_ERR);
	return (EXIT_FAILURE);
}
 */