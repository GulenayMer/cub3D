/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 16:05:56 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/header/libft.h"
# include "../libft/header/datastructures.h"
# include "messages.h"
# include "controls.h"
# include "colours.h"
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

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_pos
{
	double		x;
	double		y;
}	t_pos;

typedef struct s_fps
{
	double		cur_time;
	double		old_time;
}	t_fps;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_ray
{
	t_pos		pos;
	t_pos		delta;
	t_pos		side_dist;
	t_coord		map;
	t_coord		step;
	double		wall_dist;
	int			side;
	int			hit;
}	t_ray;

typedef struct s_colour
{
	int			red;
	int			green;
	int			blue;
}	t_colour;

typedef struct s_draw
{
	int			line_height;
	int			start;
	int			end;
	t_colour	*colour;
	int			hex_colour;
}	t_draw;

typedef struct s_data
{
	t_matrix	*map;
	t_textures	textures;
	t_pos		plane;
	t_pos		direction;
	t_pos		player;
	t_ray		ray;
	t_fps		fps;
	t_draw		draw;
	double		camera_x;
	t_image		image;
	void		*mlx;
	void		*win;
	int			xlen;
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
int		cub3d_raycast(void *input);
int		cub3d_check_square(t_data *data, t_coord map);
#endif
