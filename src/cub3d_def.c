/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:05:53 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/25 14:33:04 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static t_data	*cub3d_setup(char *map);
static void		*cub3d_error_clean(t_data *new, char *line, int fd);
static void		cub3d_setup_init(t_data *new, int y, char *line);

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
	// CONTROL NULL
	cub3d_mlx_init(data);
	cub3d_texture_init(data, block);
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

int	cub3d_convert_rgb(t_colour rgb)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*rgb;
	int		ret;

	temp1 = ft_convert2hexa(rgb.r);
	temp2 = ft_convert2hexa(rgb.g);
	temp3 = ft_convert2hexa(rgb.b);
	rgb = ft_strjoin(temp1, temp2);
	free(temp1);
	temp1 = ft_strjoin(rgb, temp3);
	ret = ft_convertfromhexa(re);
	free(temp1);
	free(temp2);
	free(temp3);
	free(rgb);
	return (ret);
}
