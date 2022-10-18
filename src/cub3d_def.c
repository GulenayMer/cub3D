/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:05:53 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/12 21:07:24 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static t_data	*cub3d_setup(char *map);
static void		*cub3d_error_clean(t_data *new, char *line, int fd);
static void		cub3d_setup_init(t_data *new, int y, char *line);

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
	cub3d_setup_init(new, y, line);
	if (new->error_check == EXIT_FAILURE)
		return (cub3d_error_clean(new, line, fd));
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd, 0);
		cub3d_fill_map(new, line, new->map, y);
		if (new->error_check == EXIT_FAILURE)
			return (cub3d_error_clean(new, line, fd));
	}
	close(fd);
	return (new);
}

static void	*cub3d_error_clean(t_data *new, char *line, int fd)
{
	free(line);
	line = get_next_line(fd, 1);
	close(fd);
	cub3d_destroyer(new, EXIT_FAILURE);
	return (NULL);
}

static	void	cub3d_setup_init(t_data *new, int y, char *line)
{
	new->error_check = 0;
	new->xlen = ft_strlen(line);
	new->map = matrix_init(new->xlen, 1, sizeof(t_cell));
	if (new->map == NULL)
	{
		new->error_check = EXIT_FAILURE;
		return ;
	}
	cub3d_fill_map(new, line, new->map, y);
}
