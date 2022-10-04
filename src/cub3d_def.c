/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:05:53 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/04 17:26:04 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static t_data	*cub3d_setup(char *map);
static int		cub3d_fill_matrix(t_data *data, char *line, t_matrix *matrix, int y);
static void		*cub3d_new_cell(t_data *data, char line, t_matrix *matrix, int x, int y);
static void		cub3d_mlx_init(t_data *data);

t_data	*cub3d_init(char *map)
{
	t_data	*data;

	data = cub3d_setup(map);
	if (data == NULL)
		return (NULL);
	cub3d_mlx_init(data);
	return (data);
}

static t_data	*cub3d_setup(char *map)
{
	t_data	*new;
	char	*line;
	int		y;
	int		fd;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		return (NULL);
	y = 0;
	new->error_check = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd, 0);
	new->xlen = ft_strlen(line);
	new->map = matrix_init(new->xlen, 1, sizeof(t_cell));
	cub3d_fill_matrix(new, line, new->map, y);
	if (new->error_check == EXIT_FAILURE)
	{
		free(line);
		line = get_next_line(fd, 1);
		close(fd);
		cub3d_destroyer(new, EXIT_FAILURE);
		return (NULL);
	}
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd, 0);
		cub3d_fill_matrix(new, line, new->map, y);
		if (new->error_check == EXIT_FAILURE)
		{
			free(line);
			line = get_next_line(fd, 1);
			close(fd);
			cub3d_destroyer(new, EXIT_FAILURE);
			return (NULL);
		}
	}
	close(fd);
	return (new);
}

static	int	cub3d_fill_matrix(t_data *data, char *line, t_matrix *matrix, int y)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (EXIT_FAILURE);
	while (line[i] != '\n' && line[i] != '\0')
	{
		cub3d_new_cell(data, line[i], matrix, i, y);
		if(data->error_check == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static	void	*cub3d_new_cell(t_data *data, char cell, t_matrix *matrix, int x, int y)
{
	t_cell	*new;

	if (y >= matrix->count_y)
	{
		if (matrix_resize(matrix, y + 1) == NULL)
			return (NULL);
	}
	new = matrix_get(matrix, x, y);
	if (cell == '1')
		new->type = TYPE_WALL;
	else if (cell == '0')
		new->type = TYPE_FLOOR;
	else if (cell == 'N')
		new->type = TYPE_N;
	else if (cell == 'S')
		new->type = TYPE_S;
	else if (cell == 'E')
		new->type = TYPE_E;
	else if (cell == 'W')
		new->type = TYPE_W;
	else if (cell == ' ' || cell == '\t')
		new->type = TYPE_NOTHING;
	else if (cell == '\n')
		new->type = TYPE_NEWLINE;
	else
		new->type = INVALID;
	if (new->type == INVALID)
		data->error_check = EXIT_FAILURE;
	return (EXIT_SUCCESS);
}

static void	cub3d_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	cub3d_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
