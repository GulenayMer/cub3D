/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_colours_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:24 by mgulenay          #+#    #+#             */
/*   Updated: 2022/11/08 12:05:17 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
		while (j < (int) ft_strlen(list[i]))
		{
			if (ft_isdigit(list[i][j]) == 0)
				return (EXIT_FAILURE);
			j += 1;
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
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
