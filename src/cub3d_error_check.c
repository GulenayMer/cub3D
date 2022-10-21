/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:07:12 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/21 10:24:55 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static int	check_first_wall(t_data *data);
static int	check_last_wall(t_data *data); */

/* static int	check_first_wall(t_data *data)
{
	int		x;
	int		y;
	t_cell	*cell;

	x = 0;
	y = 0;
	while (x < data->map->count_x)
	{
		cell = (t_cell *)matrix_get(data->map, x, y);
		if (cell->type != '1')
		{
			ft_putstr_fd("The first top wall is not complete.\n", 2);
			return (EXIT_FAILURE);
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

static int	check_last_wall(t_data *data)
{
	int		x;
	int		y;
	t_cell	*cell;

	x = 0;
	y = data->map->count_y - 1;
	while (x < data->map->count_x)
	{
		cell = (t_cell *)matrix_get(data->map, x, y);
		if (cell->type != '1')
		{
			ft_putstr_fd("The last bottom wall is not complete.\n", 2);
			return (EXIT_FAILURE);
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

static int	check_left_wall(t_data *data)
{
	int		x;
	int		y;
	t_cell	*cell;

	x = 0;
	y = 0;
	while (y < data->map->count_y)
	{
		cell = (t_cell *)matrix_get(data->map, x, y);
		if (cell->type != '1')
		{
			ft_putstr_fd("The left wall is not complete.\n", 2);
			return (EXIT_FAILURE);
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static int	check_right_wall(t_data *data)
{
	int		x;
	int		y;
	t_cell	*cell;

	x = data->map->count_x - 1;
	y = 0;
	while (y < data->map->count_y)
	{
		cell = (t_cell *)matrix_get(data->map, x, y);
		if (cell->type != '1')
		{
			ft_putstr_fd("The right wall is not complete.\n", 2);
			return (EXIT_FAILURE);
		}
		y++;
	}
	return (EXIT_SUCCESS);
} */


/* int	error_check_walls(t_data *data)
{
	if (check_first_wall(data))
		return (EXIT_FAILURE);
	if (check_last_wall(data))
		return (EXIT_FAILURE);
	if (check_left_wall(data))
		return (EXIT_FAILURE);
	if (check_right_wall(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
} */
