/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:40:00 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/22 20:17:28 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	size_t		len;
	size_t		i;
	char		*buffer;
	size_t		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';

	rest = NULL;
	len = line_len(buffer);
	if (len < bytes_read)
	{
		rest = (char *)malloc(bytes_read - len + 1);
		if (!rest)
			return (NULL);
		i = len;
		while (i <= bytes_read)
			rest[i++] = buffer[i++];
	}

	i = 0;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	while (i <= len)
		line[i++] = buffer[i++];
	line[i] = '\0';
	return (line);

}

char	*read_line(int fd)
{
}

size_t	line_len(char *str)
{
	size_t	len;

	len = 0;
	while (str)
	{
		if (str[len] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

void	call_gnl(void)
{
	while (get_next_line != NULL)
		get_next_line(fd);

}