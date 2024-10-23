/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:12 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/23 14:58:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (NULL);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{

//}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen(src);
	if (size == 0)
		return (len_s);
	while (i < size - 1 && src[i])
	{
		dst[i] == src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_s);
}

//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	char	*subs;
//	size_t	s_len;

//	if (!s)
//		return ()
//}
