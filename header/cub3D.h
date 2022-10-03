/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/03 11:14:22 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/header/libft.h"
# include "../../libft/header/datastructures.h"
# include <stdlib.h>
# include <math.h>

# define HEIGHT 720
# define WIDTH 1280
# define LINE_LEN 26
# define MOVE 10

typedef struct s_cell
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		isbottom;
	int		isright;
	int		isiso;
}	t_cell;

typedef struct s_line
{
	t_cell	*start;
	t_cell	*end;
	int		sign;
	int		p;
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;
}	t_line;

typedef struct s_fdf
{
	t_matrix	*matrix;
	char		*filename;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			len;
	int			endian;
	int			xlen;
	int			halfy;
	int			offsetx;
	int			offsety;
}	t_fdf;

t_fdf	*fdf_setup(char *map);
t_fdf	*fdf_init(char *map);
void	fdf_mlx_init(t_fdf *fdf);
int		fdf_destroyer(t_fdf *fdf);
int		x_size(char const *s, char c);
int		separate_z(char *value);
int		sepatate_color(char *value);
int		fdf_get_z(t_fdf *fdf, int index_x, int index_y);
int		fdf_get_color(t_fdf *fdf, int index_x, int index_y);
int		fdf_get_x(t_fdf *fdf, int index_x, int index_y);
int		fdf_get_y(t_fdf *fdf, int index_x, int index_y);
void	fdf_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		fdf_draw_image(void *data);
void	fdf_set_x(t_fdf *fdf, int index_x, int index_y, int value);
void	fdf_set_y(t_fdf *fdf, int index_x, int index_y, int value);
void	fdf_set_coordinates(t_fdf *fdf);
int		fdf_close_win(t_fdf *fdf);
int		fdf_key_press(int key, t_fdf *fdf);
void	fdf_draw_xy(t_fdf *fdf, t_line *line);
void	fdf_isometric(t_cell *cell, t_fdf *fdf);
void	fdf_draw_menu(t_fdf *fdf);

#endif
