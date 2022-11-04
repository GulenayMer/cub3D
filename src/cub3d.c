/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:00:45 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/04 14:10:39 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	cub3d_error_mgmt(int argc, char **argv);
static int	cub3d_argc_ctrl(int argc);

int	main(int argc, char **argv)
{
	int		error_check;
	t_data	*data;

	error_check = cub3d_error_mgmt(argc, argv);
	if (error_check == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = cub3d_init(argv[1]);
	if (data == NULL)
		return (cub3d_destroyer(data, EXIT_FAILURE));
	if (data->error_check == EXIT_FAILURE)
	{
		ft_printf(STDERR_FILENO, TEXTURE_PROBLEM);
		return (cub3d_destroyer(data, EXIT_SUCCESS));
	}
	mlx_loop_hook(data->mlx, cub3d_draw_image, data);
	mlx_hook(data->win, 2, 1L << 0L, cub3d_key_press, data);
	mlx_hook(data->win, 6, (1L << 6), cub3d_mlx_mouse, data);
	mlx_hook(data->win, 17, 0L, cub3d_close_win, data);
	mlx_loop(data->mlx);
	return (cub3d_destroyer(data, EXIT_SUCCESS));
}

static int	cub3d_error_mgmt(int argc, char **argv)
{
	int		len;
	int		fd;
	char	*file;

	if (cub3d_argc_ctrl(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(STDERR_FILENO, NO_ACCESS, argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 4], ".cub", 4) != 0)
	{
		ft_printf(STDERR_FILENO, WRNG_TYPE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	cub3d_argc_ctrl(int argc)
{
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
	return (EXIT_SUCCESS);
}
