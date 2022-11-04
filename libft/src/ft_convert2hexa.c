/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:49:37 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/04 14:35:28 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../header/libft.h"

static char	*hexer(unsigned long i, char *ret);

// The convert2hexa() function converts a given decimal represented 
// positive number, and returns a string with its hexadecimal representation.
char	*ft_convert2hexa(unsigned long i)
{
	int				cnt;
	char			*hex;
	unsigned long	wi;

	if (i == 0)
	{
		hex = ft_strdup("00");
		return (hex);
	}
	wi = i;
	cnt = 0;
	while (wi > 0)
	{
		wi /= 16;
		cnt++;
	}
	hex = ft_calloc(cnt + 2, sizeof(char));
	if (hex == NULL)
		return (NULL);
	hex = hexer(i, hex);
	hex = ft_revstring(hex);
	return (hex);
}

static char	*hexer(unsigned long i, char *ret)
{
	int	j;
	int	num;

	j = 0;
	num = 0;
	if (i == 0)
	{
		ret[j] = '0';
		j++;
	}
	else
	{
		while (i > 0)
		{
			num = i % 16;
			if (num >= 0 && num <= 9)
				ret[j] = num + '0';
			else
				ret[j] = 'a' + num - 10;
			i = i / 16;
			j++;
		}
	}
	ret[j] = '\0';
	return (ret);
}
