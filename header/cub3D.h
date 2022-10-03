/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/03 15:40:30 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/header/libft.h"
# include "../libft/header/datastructures.h"
# include "messages.h"
# include <stdlib.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

# define HEIGHT 720
# define WIDTH 1280
# define LINE_LEN 26
# define MOVE 10
# define FLOOR 0
# define WALL 1

typedef struct s_cub
{
	t_matrix	*map;
	char		*filename;
	void		*mlx;
	void		*win;
	void		*img;
	//char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			len;
	//int			endian;
	int			xlen;
	//int			halfy;
	//int			offsetx;
	//int			offsety;
}	t_cub;

#endif
