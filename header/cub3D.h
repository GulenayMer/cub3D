/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:21 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/03 14:05:34 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/header/libft.h"
# include "../libft/header/datastructures.h"
# include "messages.h"
# include <stdlib.h>
# include <math.h>

# define HEIGHT 720
# define WIDTH 1280
# define LINE_LEN 26
# define MOVE 10

typedef struct s_fdf
{
	t_matrix	*map;
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

#endif
