/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:00:45 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/04 17:03:52 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	cub3d_error_mgmt(int argc, char **argv);
static int	cub3d_argc_ctrl(int argc);

int	main(int argc, char **argv)
{
	int		error_check;
	t_data	*data;
	t_cell	*cell;
	int x, y;

	error_check = cub3d_error_mgmt(argc, argv);
	if (error_check == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = cub3d_init(argv[1]);
	if (data == NULL)
	{
		ft_printf(STDERR_FILENO, ERROR_INVALID_MAP, argv[1]);
		return (cub3d_destroyer(data, EXIT_FAILURE));
	}
	x = 0;
	y = 0;
	while (y < data->map->count_y)
	{
		while (x < data->xlen)
		{
			cell = matrix_get(data->map, x, y);
			ft_printf(STDIN_FILENO, "%i", cell->type);
			x += 1;
		}
		ft_printf(STDIN_FILENO, "\n");
		x = 0;
		y += 1;
	}
	if (error_check == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
