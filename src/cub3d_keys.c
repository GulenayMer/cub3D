/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:47 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 16:59:14 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"


int	cub3d_close_win(t_data *data)
{
	return (cub3d_destroyer(data, EXIT_SUCCESS));
}

void	cub3d_move(int key, t_data *data)
{
	if (key == W_KEY)
    {
      if(cub3d_check_square(data, (int)(data->player.x + data->direction.x * data->fps.move_speed),(int)data->player.y) == TYPE_FLOOR) 
	  	data->player.x += data->direction.x * data->fps.move_speed;
      if(cub3d_check_square(data, (int)(data->player.x),(int)(data->player.y + data->direction.y * data->fps.move_speed)) == TYPE_FLOOR) 
	  	data->player.y += data->direction.y * data->fps.move_speed;
    }
    //move backwards if no wall behind you
    /* if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    } */
}

int	cub3d_key_press(int key, t_data *data)
{
	if (key == ESC_KEY)
		cub3d_close_win(data);
	if (key == A_KEY)
		cub3d_move(A_KEY, data);
	if (key == D_KEY)
		cub3d_move(D_KEY, data);
	if (key == W_KEY)
		cub3d_move(W_KEY, data);
	if (key == S_KEY)
		cub3d_move(S_KEY, data);
	/* if (key == Q_KEY)
		cub3d_rotate(Q_KEY, data);
	if (key == E_KEY)
		cub3d_rotate(E_KEY, data); */
	return (0);
}