/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfbresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:41:43 by jrocha            #+#    #+#             */
/*   Updated: 2022/05/06 14:13:52 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	fdf_draw_low(t_fdf *fdf, t_line *line, t_cell *start, t_cell *end);
static void	fdf_draw_high(t_fdf *fdf, t_line *line, t_cell *start, t_cell *end);

void	fdf_draw_xy(t_fdf *fdf, t_line *line)
{
	if (abs(line->end->y - line->start->y) < abs(line->end->x - line->start->x))
	{
		if (line->start->x > line->end->x)
			fdf_draw_low(fdf, line, line->end, line->start);
		else
			fdf_draw_low(fdf, line, line->start, line->end);
	}
	else
	{
		if (line->start->y > line->end->y)
			fdf_draw_high(fdf, line, line->end, line->start);
		else
			fdf_draw_high(fdf, line, line->start, line->end);
	}
}

static void	fdf_draw_low(t_fdf *fdf, t_line *line, t_cell *start, t_cell *end)
{
	line->x = start->x;
	line->y = start->y;
	line->delta_x = end->x - start->x;
	line->delta_y = end->y - start->y;
	line->sign = 1;
	if (line->delta_y < 0)
	{
		line->sign = -1;
		line->delta_y = -line->delta_y;
	}
	line->p = (2 * line->delta_y) - line->delta_x;
	while (line->x != end->x && line->y != end->y)
	{	
		if ((line->y < HEIGHT && line->x < WIDTH)
			&& (line->y >= 0 && line->x >= 0))
			fdf_mlx_pixel_put(fdf, line->x, line->y, start->color);
		if (line->p > 0)
		{
			line->y = line->y + line->sign;
			line->p = line->p + (2 * (line->delta_y - line->delta_x));
		}
		else
			line->p = line->p + 2 * line->delta_y;
		line->x++;
	}	
}

static void	fdf_draw_high(t_fdf *fdf, t_line *line, t_cell *start, t_cell *end)
{
	line->x = start->x;
	line->y = start->y;
	line->delta_x = end->x - start->x;
	line->delta_y = end->y - start->y;
	line->sign = 1;
	if (line->delta_x < 0)
	{
		line->sign = -1;
		line->delta_x = -line->delta_x;
	}
	line->p = (2 * line->delta_x) - line->delta_y;
	while (line->x != end->x && line->y != end->y)
	{	
		if ((line->y < HEIGHT && line->x < WIDTH)
			&& (line->y >= 0 && line->x >= 0))
			fdf_mlx_pixel_put(fdf, line->x, line->y, start->color);
		if (line->p > 0)
		{
			line->x = line->x + line->sign;
			line->p = line->p + (2 * (line->delta_x - line->delta_y));
		}
		else
			line->p = line->p + 2 * line->delta_x;
		line->y++;
	}	
}
