/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:12:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/07 12:02:42 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	type;

	y = 0;
	while (y < data->map->count_y)
	{
		x = 0;
		type = cub3d_check_square(data, x, y);
		while (type != TYPE_NEWLINE && type != TYPE_END)
		{
			if (check_walls(data, x, y))
				return (EXIT_FAILURE);
			if (check_spaces(data, x, y))
				return (EXIT_FAILURE);
			x += 1;
			type = cub3d_check_square(data, x, y);
		}
		y += 1;
	}
	return (EXIT_SUCCESS);
}

int	cub3d_check_tex_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(STDERR_FILENO, INVALID_PATH, path);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
