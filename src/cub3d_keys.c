/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:47 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/10 13:50:04 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	cub3d_key_press(int key, t_data *data)
{
	if (key == ESC_KEY)
		cub3d_close_win(data);
	/* if (key == A_KEY)
		fdf_move(A_KEY, fdf);
	if (key == D_KEY)
		fdf_move(D_KEY, fdf);
	if (key == W_KEY)
		fdf_move(W_KEY, fdf);
	if (key == S_KEY)
		fdf_move(S_KEY, fdf);
	if (key == Q_KEY)
		fdf_zoom(Q_KEY, fdf);
	if (key == E_KEY)
		fdf_zoom(E_KEY, fdf); */
	return (0);
}

int	cub3d_close_win(t_data *data)
{
	return (cub3d_destroyer(data, EXIT_SUCCESS));
}
