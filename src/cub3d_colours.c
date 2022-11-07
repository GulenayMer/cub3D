/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:56:40 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/07 15:51:41 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	cub3d_ctrl_colour(char **colours);
static void	cub3d_free_colours(char **args);

int	cub3d_list_len(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
		i += 1;
	return (i);
}

int	cub3d_check_digits(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i] != NULL)
	{
		j = 0;
		while(j < (int) ft_strlen(list[i]))
		{
			if (ft_isdigit(list[i][j]) == 0)
				return (EXIT_FAILURE);
			j += 1;
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}

int	cub3d_set_colours(t_data *data, char *line, int type)
{
	char	**colours;
	char	*ctrl;

	ctrl = ft_strtrim(line, "\n");
	colours = ft_split(ctrl, ',');
	if (cub3d_list_len(colours) != 3 || cub3d_check_digits(colours) == EXIT_FAILURE)
	{
		free(ctrl);
		cub3d_free_colours(colours);
		return (EXIT_FAILURE);	
	}
	free(ctrl);
	if (cub3d_ctrl_colour(colours) == EXIT_FAILURE)
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

int	cub3d_convert_rgb(t_colour rgb)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*temp4;
	int		ret;

	temp1 = ft_convert2hexa(rgb.red);
	temp2 = ft_convert2hexa(rgb.green);
	temp3 = ft_convert2hexa(rgb.blue);
	temp4 = ft_strjoin(temp1, temp2);
	free(temp1);
	temp1 = ft_strjoin(temp4, temp3);
	ret = ft_convertfromhexa(temp1);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	return (ret);
}
