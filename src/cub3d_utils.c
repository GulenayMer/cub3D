/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:20:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/08 14:16:58 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

char	*cub3d_get_line(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	return (line);
}

int	cub3d_clean_line(char *line, int fd)
{
	if (line != NULL)
		free(line);
	line = get_next_line(fd);
	while (line != NULL)
		line = cub3d_get_line(line, fd);
	if (line != NULL)
		free(line);
	return (EXIT_SUCCESS);
}

int	cub3d_close_win(t_data *data)
{
	return (cub3d_destroyer(data, EXIT_SUCCESS));
}

void	cub3d_draw_line(t_data *data, int col, t_draw draw)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < draw.start)
			cub3d_mlx_pixel_put(data, col, y, data->draw.ceiling_colour);
		else if (y >= draw.start && y <= draw.end)
		{
			while (y <= draw.end)
			{
				cub3d_get_texture(data);
				cub3d_mlx_pixel_put(data, col, y, data->tex.colour);
				y += 1;
			}
		}
		else
			cub3d_mlx_pixel_put(data, col, y, data->draw.floor_colour);
		y += 1;
	}
}

int	cub3d_check_square(t_data *data, int x, int y)
{
	int		ret;
	t_cell	*cell;

	ret = -1;
	cell = (t_cell *)matrix_get(data->map, x, y);
	if (cell != NULL)
		ret = cell->type;
	return (ret);
}
