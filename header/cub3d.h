/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/18 17:20:00 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/header/libft.h"
# include "../libft/header/datastructures.h"
# include "messages.h"
# include "controls.h"
# include "../minilibx_linux/mlx.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <math.h>

# if !defined (HEIGHT)
#  define HEIGHT 720
# endif

# if !defined (WIDTH)
#  define WIDTH 1280
# endif

# define LINE_LEN 26
# define MOVE 10

typedef struct s_textures
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
}	t_textures;

typedef enum e_type
{
	INVALID = -2,
	TYPE_NOTHING = -1,
	TYPE_FLOOR = 0,
	TYPE_WALL,
	TYPE_SPRITE,
	TYPE_DOOR,
	TYPE_N,
	TYPE_E,
	TYPE_S,
	TYPE_W,
	TYPE_NEWLINE,
}	t_type;

typedef struct s_cell
{
	t_type	type;
}	t_cell;

typedef struct s_int_xy
{
	int		x;
	int		y;
}	t_int_xy;

typedef struct s_plane
{
	double		x;
	double		y;
}	t_plane;

typedef struct s_dir
{
	double		x;
	double		y;
}	t_dir;

typedef struct s_pos
{
	double		x;
	double		y;
}	t_pos;

typedef struct s_data
{
	t_matrix	*map;
	t_textures	textures;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			len;
	int			xlen;
	int			endian;
	int			error_check;
}	t_data;

t_data	*cub3d_init(char *map);
int		cub3d_fill_map(t_data *data, char *line, t_matrix *matrix,
			int y);
int		cub3d_destroyer(t_data *data, int exit_status);
void	cub3d_mlx_init(t_data *data);
void	cub3d_mlx_pixel_put(t_data *data, int x, int y, int color);
int		cub3d_draw_image(void *input);
int		cub3d_key_press(int key, t_data *data);
int		cub3d_close_win(t_data *data);

#endif
