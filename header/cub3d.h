/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/29 12:36:37 by jrocha           ###   ########.fr       */
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
# include <stdio.h>
# include <sys/time.h>
# include <math.h>

# if !defined (HEIGHT)
#  define HEIGHT	720
# endif

# if !defined (WIDTH)
#  define WIDTH		1280
# endif

# define TEX_SIZE	256

# define NORTH "./textures/NorthXL.xpm"
# define SOUTH "./textures/SouthXL.xpm"
# define EAST "./textures/EastXL.xpm"
# define WEST "./textures/WestXL.xpm"
# define X_OFFSET WIDTH - 30
# define Y_OFFSET 30

typedef enum e_type
{
	INVALID = -3,
	TYPE_END = -2,
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
	long long	cur_time;
	long long	old_time;
	double		frame_time;
	double		move_speed;
	double		rotate_speed;
}	t_fps;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_tex_img
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_tex_img;

typedef struct s_textures
{
	t_tex_img		no;
	t_tex_img		so;
	t_tex_img		we;
	t_tex_img		ea;
	t_coord			coord;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_num;
	int				colour;
}	t_textures;


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
	t_colour	ceiling;
	t_colour	floor;
	int			ceiling_colour;
	int			floor_colour;
}	t_draw;

typedef struct s_minimap
{
	t_coord		size;
	t_coord		unit;
	t_coord		map;
	t_coord		iter;
	t_coord		p_size;
	t_coord		p_unit;
}	t_minimap;

typedef struct s_data
{
	t_matrix	*map;
	t_textures	tex;
	t_minimap	minimap;
	t_pos		plane;
	t_pos		old_plane;
	t_pos		direction;
	t_pos		old_dir;
	t_pos		player;
	t_ray		ray;
	t_fps		fps;
	t_draw		draw;
	t_image		image;
	t_coord		mouse;
	int			ctr_x;
	double		camera_x;
	void		*mlx;
	void		*win;
	int			xlen;
	int			error_check;
}	t_data;

t_data		*cub3d_init(char *map);
int			cub3d_fill_map(t_data *data, char *line, t_matrix *matrix, int y);
int			cub3d_destroyer(t_data *data, int exit_status);
void		cub3d_mlx_init(t_data *data);
void		cub3d_mlx_pixel_put(t_data *data, int x, int y, int color);
int			cub3d_draw_image(void *input);
int			cub3d_key_press(int key, t_data *data);
int			cub3d_close_win(t_data *data);
void		cub3d_raycast(t_data *data);
int			cub3d_check_square(t_data *data, int x, int y);
void		cub3d_find_player(t_data *data);
void		cub3d_direction_set(t_data *data, char cell);
void		cub3d_init_dir_plane(t_data *data, t_coord coord, char cell);
void		cub3d_init_plane(t_data *data, char cell);
long long	cub3d_get_time(void);
void		cub3d_draw_line(t_data *data, int col, t_draw draw);
void		cub3d_check_fps(t_data *data);
int			error_check_walls(t_data *data);
int			cub3d_texture_init(t_data *data, int block);
void		cub3d_get_texture(t_data *data);
void		cub3d_calculate_wallx(t_data *data);
void		cub3d_rotate_left(t_data *data, double rotate_speed);
void		cub3d_rotate_right(t_data *data, double rotate_speed);
int			cub3d_mlx_mouse(int x, int y, t_data *data);
int			cub3d_convert_rgb(t_colour rgb);
void		cub3d_minimap(t_data *data);


#endif
