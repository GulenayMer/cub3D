/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:51 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/03 16:56:31 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	cub3d_free_colours(char **args);

int	cub3d_draw_image(void *input)
{
	t_data	*data;

	data = (t_data *)input;
	ft_bzero(data->image.addr, (WIDTH * HEIGHT) * sizeof(int));
	cub3d_raycast(data);
	cub3d_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	cub3d_set_colours(t_data *data, char *line, int type)
{
	char	**colours;
	char	*ctrl;

	ctrl = ft_strtrim(line, "\n");
	colours = ft_split(ctrl, ',');
	free(ctrl);
	if ((ft_atoi(colours[0]) > 255 || ft_atoi(colours[0]) < 0)
		|| (ft_atoi(colours[1]) > 255 || ft_atoi(colours[1]) < 0)
		|| (ft_atoi(colours[2]) > 255 || ft_atoi(colours[2]) < 0))
		return (EXIT_FAILURE);
	if (type == 0)
	{
		data->draw.ceiling.red = ft_atoi(colours[0]);
		data->draw.ceiling.green = ft_atoi(colours[1]);
		data->draw.ceiling.blue = ft_atoi(colours[2]);
		data->draw.ceiling_colour = cub3d_convert_rgb(data->draw.ceiling);
	}
	else if (type == 1)
	{
		data->draw.floor.red = ft_atoi(colours[0]);
		data->draw.floor.green = ft_atoi(colours[1]);
		data->draw.floor.blue = ft_atoi(colours[2]);
		data->draw.floor_colour = cub3d_convert_rgb(data->draw.floor);
	}
	cub3d_free_colours(colours);
	return (EXIT_SUCCESS);
}

static void	cub3d_free_colours(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		i += 1;
	}
	while (i >= 0)
	{
		if (args[i] != NULL)
			free(args[i]);
		i -= 1;
	}
	free(args);
}
