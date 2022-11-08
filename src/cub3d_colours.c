/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:56:40 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/08 12:23:12 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	cub3d_ctrl_colour(char **colours);
static void	cub3d_free_colours(char **args);
static void	set_colours_helper(t_data *data, char **colours, int type);

int	cub3d_set_colours(t_data *data, char *line, int type)
{
	char	**colours;
	char	*ctrl;

	ctrl = ft_strtrim(line, "\n");
	if (ctrl[ft_strlen(ctrl) - 1] == ',')
	{
		free(ctrl);
		return (EXIT_FAILURE);
	}
	colours = ft_split(ctrl, ',');
	if (cub3d_list_len(colours) != 3
		|| cub3d_check_digits(colours) == EXIT_FAILURE)
	{
		free(ctrl);
		cub3d_free_colours(colours);
		return (EXIT_FAILURE);
	}
	free(ctrl);
	if (cub3d_ctrl_colour(colours) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_colours_helper(data, colours, type);
	cub3d_free_colours(colours);
	return (EXIT_SUCCESS);
}

static void	set_colours_helper(t_data *data, char **colours, int type)
{
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
}

static int	cub3d_ctrl_colour(char **colours)
{
	if (ft_atoi(colours[0]) > 255 || ft_atoi(colours[0]) < 0)
	{
		cub3d_free_colours(colours);
		return (EXIT_FAILURE);
	}
	else if (ft_atoi(colours[1]) > 255 || ft_atoi(colours[1]) < 0)
	{
		cub3d_free_colours(colours);
		return (EXIT_FAILURE);
	}
	else if (ft_atoi(colours[2]) > 255 || ft_atoi(colours[2]) < 0)
	{
		cub3d_free_colours(colours);
		return (EXIT_FAILURE);
	}
	else
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

int	cub3d_colour_check(t_data *data, char *line, char *type)
{
	if (ft_strncmp("F ", type, 2) == 0)
	{
		if (cub3d_set_colours(data, &line[2], 1) == EXIT_FAILURE)
		{
			data->error_check = 1;
			return (EXIT_FAILURE);
		}
		data->tex.val.f += 1;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp("C ", type, 2) == 0)
	{
		if (cub3d_set_colours(data, &line[2], 0) == EXIT_FAILURE)
		{
			ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
			data->error_check = 1;
		}
		data->tex.val.c += 1;
		return (TRUE);
	}
	return (EXIT_FAILURE);
}
