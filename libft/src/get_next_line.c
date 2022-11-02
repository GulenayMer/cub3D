/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:57:34 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/02 17:40:42 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../header/libft.h"

char	*ft_strjoin_gnl(char *chars_saved, char *temp)
{
	size_t	len;
	size_t  len1;
	size_t	len2;
	char	*new;

	if (!chars_saved && !temp)
		return (0);
	if (chars_saved == NULL)
		len1 = 0;
	else
		len1 = ft_strlen((char *)chars_saved);
	if (temp == NULL)
		len2 = 0;
	else
			len2 = ft_strlen((char *)temp);
	len = len1 + len2;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	ft_memmove(new, chars_saved, len1);
	ft_memmove(new + len1, temp, len2);
	new[len] = '\0';
	free(chars_saved);
	return (new);
}

char	*ft_update_static(char *chars_read)
{
	char	*new_static;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_strlen(chars_read);
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
		i++;
	if (!chars_read[i])
	{
		free(chars_read);
		return (0);
	}
	new_static = (char *)malloc(sizeof(char) * (size - i) + 1);
	if (!new_static)
		return (0);
	i++;
	j = 0;
	while (chars_read[i] != '\0')
		new_static[j++] = chars_read[i++];
	new_static[j] = '\0';
	free(chars_read);
	return (new_static);
}

char	*ft_extract_line(char *chars_read)
{
	int		i;
	char	*line;

	i = 0;
	if (!chars_read[i])
		return (0);
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
	{
		line[i] = chars_read[i];
		i++;
	}
	if (chars_read[i] == '\n')
	{
		line[i] = chars_read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *chars_read)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (100 + 1));
	if (!buffer)
		return (0);
	bytes_read = 1;
	while (!ft_strchr(chars_read, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 100);
		if (bytes_read < 0)
		{
			free(buffer);
			return (0);
		}
		else
		{
			buffer[bytes_read] = '\0';
			chars_read = ft_strjoin_gnl(chars_read, buffer);
		}
	}
	free(buffer);
	return (chars_read);
}

char	*get_next_line(int fd)
{
	static char	*chars_read;
	char		*line;

	if (fd < 0)
		return (0);
	chars_read = ft_read_file(fd, chars_read);
	if (!chars_read)
		return (0);
	line = ft_extract_line(chars_read);
	chars_read = ft_update_static(chars_read);
	return (line);
}
