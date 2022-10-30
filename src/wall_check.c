/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:25:04 by mgulenay          #+#    #+#             */
/*   Updated: 2022/10/30 13:32:37 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_characters(t_data *data, char **map, int x, int y)
{
	if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ' \
		&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E' \
		&& map[y][x] != 'W')
		return (1);
	return (0);
}

int	check_edge_walls(t_data *data, char *map, int x, int y)
{
	if ((y == 0 || y == data->check_row - 1) \
		&& map[y][x] != '1' && map[y][x] != ' ')
		return (1);
	else if ((x == 0 || x == data->check_columns - 1) \
		&& map[y][x] != '1' && map[y][x] != ' ')
		return (1);
	return (0);
}

int	check_spaces(t_data *data, char *map, int x, int y)
{
	if (map[y][x + 1] != ' ' || map[y][x - 1] != ' ' \
		|| map[y - 1] == ' ' || map[y + 1][x] == ' ')
		return (1);
	return (0);
}

int	check_inside(t_data *data, char *line, int x, int y)
{
	if (line[0] == '0' && y != 0 && y != data->check_rows - 1
		x != 0 && x != ft_strlen(s) - 1)
		return (1);
	return (0);
}

int	check_inside2(t_data *data, char **map, int x, int y)
{
	if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' \
		|| map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
		return (1);
	return (0);
}

int	check_map(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_characters(data, map, x, y) \
				|| check_edge_walls(data, map, x, y))
				return (1);
			else if (check_inside(data, &map[y][x], x, y))
			{
				if (check_inside2(data, map[y][x], x, y))
					return (1);
			}
			x += 1;
		}
		y += 1;
	}
	return (0);
}
