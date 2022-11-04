/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:05:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/04 14:43:02 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static char	*cub3d_parsing_main_loop(t_data *data, char *line, int fd);
static int	cub3d_texture_check_ns(t_data *data, char *line, char *card);
static int	cub3d_texture_check_ew(t_data *data, char *line, char *card);
static int	cub3d_texture_check(t_data *data, char *line, char *card);

int	cub3d_map_parsing(t_data *data, char *line, int fd)
{
	cub3d_validator_init(data);
	line = cub3d_parsing_main_loop(data, line, fd);
	if (data->error_check == 1)
	{
		ft_printf(STDERR_FILENO, INVALID_VALUES, data->name);
		return (EXIT_FAILURE);
	}
	if (cub3d_validator(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cub3d_map_init(data);
	cub3d_fill_map(data, line, data->map, 0);
	if (cub3d_map_end(data, line, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*cub3d_parsing_main_loop(t_data *data, char *line, int fd)
{
	while (line != NULL && data->error_check == 0)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			data->error_check = cub3d_texture_check(data, line, "NO ");
		else if (ft_strncmp(line, "SO ", 3) == 0)
			data->error_check = cub3d_texture_check(data, line, "SO ");
		else if (ft_strncmp(line, "WE ", 3) == 0)
			data->error_check = cub3d_texture_check(data, line, "WE ");
		else if (ft_strncmp(line, "EA ", 3) == 0)
			data->error_check = cub3d_texture_check(data, line, "EA ");
		else if (ft_strncmp("F ", line, 2) == 0)
			data->error_check = cub3d_colour_check(data, line, "F ");
		else if (ft_strncmp("C", line, 1) == 0)
			data->flag = cub3d_colour_check(data, line, "C ");
		else if (ft_strncmp("\n", line, 1) == 0)
			data->counter += 1;
		else if (ft_strncmp("\n", line, 1) != 0 && data->flag == 1)
			break ;
		else
			data->error_check = 1;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	cub3d_texture_check_ns(t_data *data, char *line, char *card)
{
	if (ft_strncmp(card, "NO ", 3) == 0)
	{
		data->tex.no.path = ft_strtrim(&line[3], "\n");
		if (cub3d_check_tex_path(data->tex.no.path) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		data->tex.val.no += 1;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(card, "SO ", 3) == 0)
	{
		data->tex.so.path = ft_strtrim(&line[3], "\n");
		if (cub3d_check_tex_path(data->tex.so.path) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		data->tex.val.so += 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	cub3d_texture_check_ew(t_data *data, char *line, char *card)
{
	if (ft_strncmp(card, "WE ", 3) == 0)
	{
		data->tex.we.path = ft_strtrim(&line[3], "\n");
		if (cub3d_check_tex_path(data->tex.we.path) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		data->tex.val.we += 1;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(card, "EA ", 3) == 0)
	{
		data->tex.ea.path = ft_strtrim(&line[3], "\n");
		if (cub3d_check_tex_path(data->tex.ea.path) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		data->tex.val.ea += 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	cub3d_texture_check(t_data *data, char *line, char *card)
{
	if (ft_strncmp(card, line, 3) == 0)
	{
		if (cub3d_texture_check_ns(data, line, card) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (cub3d_texture_check_ew(data, line, card) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
