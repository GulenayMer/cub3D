/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/04 13:26:13 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/header/libft.h"
# include "../libft/header/datastructures.h"
# include "messages.h"
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

typedef struct s_data
{
	t_matrix	*map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			len;
	int			xlen;
	int			endian;
}	t_data;

typedef enum e_type {
	WALL,
	PLAYER,
	FLOOR,
}	t_type;

typedef struct s_cell
{
	t_type	type;
}	t_cell;

t_data	*cub3d_init(char *map);

#endif
