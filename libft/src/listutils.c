/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:54:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/10/03 12:11:37 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/datastructures.h"

int	list_total(t_list *list)
{
	if (list == NULL)
		return (0);
	return (list->total);
}

int	list_capacity(t_list *list)
{
	if (list == NULL)
		return (0);
	return (list->capacity);
}

void	list_destroyer(t_list *list)
{
	free(list->nodes[0]);
	free(list->nodes);
	free(list);
}
