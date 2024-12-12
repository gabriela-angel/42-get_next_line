/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:40:00 by gangel-a          #+#    #+#             */
/*   Updated: 2024/12/12 20:51:45 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_nullify(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

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

static char	*read_file(char **ptr, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!*ptr)
		*ptr = initialize_empty();
	if (!*ptr)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_nullify(&buffer));
		buffer[bytes_read] = '\0';
		*ptr = ft_strjoin(*ptr, buffer);
		if (ft_strchr(*ptr, '\n') != -1)
			break ;
	}
	free(buffer);
	return (*ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read;
	int			end_line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !read_file(&read, fd))
		return (free_and_nullify(&read));
	end_line = ft_strchr(read, '\n');
	if (end_line < 0)
	{
		line = ft_substr(read, 0, ft_strlen(read));
		free_and_nullify(&read);
	}
	else
	{
		line = ft_substr(read, 0, end_line + 1);
		read = cut_line(&read, end_line + 1);
	}
	if (!line)
		return (free_and_nullify(&read));
	return (line);
}

//#include <fcntl.h>
//#include <stdio.h>

//int	main(void)
//{
//	int	fd = open("teste.txt", O_RDWR);
//	char	*ptr = NULL;

//	ptr = get_next_line(fd);
//	while (ptr && *ptr)
//	{
//		printf("%s", ptr);
//		free(ptr);
//		ptr = get_next_line(fd);
//	}
//	close(fd);
//	return (0);
//}
