/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pop_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:19:11 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/19 12:49:44 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void		*cub3d_new_cell(t_data *data, char line, t_matrix *matrix,
					t_coord coord);
static void		cub3d_new_cell_type(t_data *data, t_cell *new, char cell);

int	cub3d_fill_map(t_data *data, char *line, t_matrix *matrix, int y)
{
	t_coord	coord;

	coord.x = 0;
	coord.y = y;
	if (line == NULL)
		return (EXIT_FAILURE);
	while (line[coord.x] != '\n' && line[coord.x] != '\0')
	{
		cub3d_new_cell(data, line[coord.x], matrix, coord);
		if (data->error_check == EXIT_FAILURE)
			return (EXIT_FAILURE);
		coord.x += 1;
	}
	return (EXIT_SUCCESS);
}

static	void	*cub3d_new_cell(t_data *data, char cell, t_matrix *matrix,
						t_coord coord)
{
	t_cell	*new;

	if (coord.y >= matrix->count_y)
	{
		if (matrix_resize(matrix, coord.y + 1) == NULL)
			return (NULL);
	}
	new = matrix_get(matrix, coord.x, coord.y);
	cub3d_new_cell_type(data, new, cell);
	return (EXIT_SUCCESS);
}

static void	cub3d_new_cell_type(t_data *data, t_cell *new, char cell)
{
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
}
