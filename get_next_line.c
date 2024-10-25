/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:40:00 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/24 21:34:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd);
void	update_rest(char **ptr, char *str, char mode);
char	*populate_line(char *buffer, char *rest);


char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*rest;
buffer &&
	update_rest(&rest, "", 'a');
	buffer = read_file(fd);
	line = populate_line(buffer, rest);
	if (!line)
		return (NULL);
	if (!*line)
		line = get_next_line(fd);
	return (line);
}

char	*read_file(int fd)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

void	update_rest(char **ptr, char *str, char mode)
{
	char		*temp;

	temp = NULL;
	if (!*ptr)
		*ptr = ft_strdup("");
	if (!mode || (mode != 'c' && mode != 'a'))
		return ;
	if (mode == 'c')
		temp = ft_substr(str, line_len(str), ft_strlen(str) - line_len(str));
	else if (mode == 'a')
		temp = ft_strjoin(*ptr, str);
	free(*ptr);
	*ptr = ft_strdup(temp);
	free(temp);
	return ;
}

char	*populate_line(char *buffer, char *rest)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	if (*rest)
	{
		if (ft_strchr(rest, '\n') == NULL)
		{
			if (buffer && ft_strchr(buffer, '\n') == NULL)
			{
				update_rest(&rest, buffer, 'a');
				return (ft_strdup(""));
			}
			else if (buffer)
			{
				temp = ft_substr(buffer, 0, line_len(buffer));
				line = ft_strjoin(rest, temp);
				free(temp);
				update_rest(&rest, buffer, 'c');
			}
			else
			{
				line = ft_substr(rest, 0, ft_strlen(rest));
			}
		}
		else
		{
			line = ft_substr(rest, 0, line_len(rest));
			update_rest(&rest, rest, 'c');
		}
	}
	else
	{
		if (ft_strchr(buffer, '\n') == NULL)
		{
			update_rest(&rest, buffer, 'a');
			return (ft_strdup(""));
		}
		else
		{
			line = ft_substr(buffer, 0, line_len(buffer));
			update_rest(&rest, buffer, 'c');
		}
	}
	if (!line)
		return (NULL);
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int	fd = open("teste.txt", O_RDWR);
	int	i = 0;

	while (get_next_line(fd) != NULL)
		i++;
	return (0);
}
