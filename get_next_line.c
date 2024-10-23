/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:40:00 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/23 14:15:19 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// NAO TRATADO:
//E SE A GNT AINDA NAO TIVER CHEGADO NUMA queBRA De LINHA E O ARQUIVO NSO TIVER TERMINADO)
	char		*line;
	static char	*rest;
	size_t		rest_len;
	size_t		len;
	size_t		i;
	char		*buffer;
	size_t		bytes_read;
	char		*temp;

	i = 0;

	// PROCESSO DE LEITURA
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';

	// ONLY IF REST == NULL;
	// CREATE REST
	rest_len = bytes_read - line_len(buffer);
	rest = (char *)malloc(rest_len + 1);
	if (!rest)
		return (NULL);

	// CREATE LINE
	if (*rest)
	{
		len = line_len(rest);
		if (rest[len] != '\n')
			len += line_len(buffer);
	}
	else
		len = line_len(buffer);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	return (line);

	// POPULATE LINE
	i = 0;
	j = 0;
	if (!*rest)
	{
		while (rest[i] != '\n' && rest[i])
			line[i++] = rest[i++];
		if (rest[i] == '\n')
		{
			line[i] == rest[i];
			return (line);
		}
	}
	while (buffer[j] != '\n' && buffer[j])
		line[i] = buffer[j];
	if (buffer[j] == '\n')
		line[i] == buffer[j];
	return (line);

	// IF *REST = NULL
	if (*rest == NULL)
		// POPULATE REST
		while (buffer[len + i])
			rest[i++] = buffer[len + i++];
	else
	// ELSE IF *REST != NULL
		//REMOVE PART THAT WAS COPIED TO LINE FROM REST
		//AND FREE IF REST GETS EMPTY
		while ()
		{

		}

}

int	line_count(char *str)
{
	int	lines;
	int	i;

	lines = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

size_t	line_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

#include <fcntl.h>

void	main(void)
{
	int	fd = open("teste.txt", O_RDWR);
	
	while (get_next_line != NULL)
		get_next_line(fd);
}