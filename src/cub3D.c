/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:00:45 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/03 15:41:07 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc < 2)
	{
		ft_printf(STDERR_FILENO, WRNG_NUM_ARGS1);
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf(STDERR_FILENO, WRNG_NUM_ARGS2);
		return (EXIT_FAILURE);
	}
	if (argc == 2)
	{
		ft_printf(STDIN_FILENO, "%s\n", argv[1]);
	}
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "cub3D");
	mlx_loop(cub.mlx);
	return (EXIT_SUCCESS);
}
