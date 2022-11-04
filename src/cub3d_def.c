/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:05:53 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/04 14:08:13 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static t_data	*cub3d_setup(char *map);
static void		cub3d_setup_init(t_data *new, int fd);

t_data	*cub3d_init(char *map)
{
	t_data	*data;
	int		block;

	block = TEX_SIZE;
	data = cub3d_setup(map);
	if (data == NULL)
		return (NULL);
	data->fps.cur_time = 0;
	data->fps.old_time = 0;
	data->ctr_x = WIDTH / 2;
	data->mouse.x = WIDTH / 2;
	data->mouse.y = HEIGHT / 2;
	cub3d_mlx_init(data);
	data->error_check = cub3d_texture_init(data, block);
	return (data);
}

static t_data	*cub3d_setup(char *map)
{
	t_data	*new;
	int		fd;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new->error_check = 0;
	new->xlen = cub3d_check_max_len(map) + 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(new);
		return (NULL);
	}
	new->name = map;
	cub3d_setup_init(new, fd);
	if (new->error_check == EXIT_FAILURE)
		return (cub3d_error_clean(new, fd));
	close(fd);
	return (new);
}

void	*cub3d_error_clean(t_data *new, int fd)
{
	close(fd);
	cub3d_destroyer(new, EXIT_FAILURE);
	return (NULL);
}

static	void	cub3d_setup_init(t_data *new, int fd)
{
	char	*line;

	line = get_next_line(fd);
	new->error_check = 0;
	if (cub3d_map_parsing(new, line, fd) == EXIT_FAILURE)
	{
		new->error_check = EXIT_FAILURE;
		return ;
	}
	if (check_map(new) == EXIT_FAILURE)
	{
		new->error_check = EXIT_FAILURE;
		return ;
	}
}
