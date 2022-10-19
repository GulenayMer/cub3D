/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:45:18 by jrocha            #+#    #+#             */
/*   Updated: 2022/05/06 14:33:13 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	*fdf_draw_lines(t_fdf *fdf, int coord_x, int coord_y);

int	fdf_draw_image(void *data)
{
	int		x;
	int		y;
	t_fdf	*fdf;

	fdf = data;
	y = 0;
	ft_bzero(fdf->addr, (WIDTH * HEIGHT) * sizeof(int));
	fdf_set_coordinates(fdf);
	while (y < fdf->matrix->count_y)
	{
		x = 0;
		while (x < fdf->matrix->count_x)
		{
			fdf_draw_lines(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	fdf_draw_menu(fdf);
	return (0);
}

static void	*fdf_draw_lines(t_fdf *fdf, int coord_x, int coord_y)
{
	t_cell	*current;
	t_cell	*next;
	t_cell	*bot;
	t_line	*line;

	line = ft_calloc(1, sizeof(t_line));
	current = (t_cell *) matrix_get(fdf->matrix, coord_x, coord_y);
	if (current->isright == 0)
	{
		next = (t_cell *)matrix_get(fdf->matrix, coord_x + 1, coord_y);
		line->start = current;
		line->end = next;
		fdf_draw_xy(fdf, line);
	}
	if (current->isbottom == 0)
	{
		bot = (t_cell *)matrix_get(fdf->matrix, coord_x, coord_y + 1);
		line->start = bot;
		line->end = current;
		fdf_draw_xy(fdf, line);
	}
	free(line);
	return (0);
}
