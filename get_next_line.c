/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:40:00 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/30 14:54:11 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*initialize_empty(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

static char	*cut_line(char **ptr, size_t start)
{
	char	*temp;

	temp = ft_substr(*ptr, start, ft_strlen(*ptr) - start);
	free(*ptr);
	*ptr = temp;
	return (*ptr);
}

static int	read_file(char **ptr, int fd)
{
	char	*buffer;
	size_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!*ptr)
		*ptr = initialize_empty();
	if (!*ptr)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*ptr = ft_strjoin(*ptr, buffer);
		if (ft_strchr(*ptr, '\n') != -1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read;
	int			end_line;

	line = NULL;
	if (!read_file(&read, fd))
		return (NULL);
	end_line = ft_strchr(read, '\n');
	if (end_line < 0)
	{
		line = ft_substr(read, 0, ft_strlen(read));
		free(read);
		read = NULL;
	}
	else
	{
		line = ft_substr(read, 0, end_line + 1);
		read = cut_line(&read, end_line + 1);
	}
	if (!line)
	{
		free(read);
		return (NULL);
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("teste.txt", O_RDWR);
	char	*ptr = NULL;

	ptr = get_next_line(fd);
	while (ptr && *ptr)
	{
		printf("%s", ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	return (0);
}
