/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:01:50 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/16 04:41:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void		*target;
	uint64_t	size;
	int			i;

	if (nelem == 0 || elsize == 0)
		return (malloc(1));
	if ((int64_t)nelem < 0 || (int64_t)elsize < 0)
		return (NULL);
	size = nelem * elsize;
	if (size > SIZE_MAX)
		return (NULL);
	target = (void *)malloc((size_t)size);
	if (target)
		i = 0;
	if (target)
		while (i < (int)size)
			((char *)target)[i++] = 0;
	return (target);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;

	if (!dst && !src)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char *)src;
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == (unsigned char)c)
				return ((char *)s);
			s++;
		}
		if ((unsigned char)c == 0)
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	new_length;
	char	*substr;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
	{
		substr = malloc(1);
		*substr = 0;
		return (substr);
	}
	new_length = ft_strlen(s + start);
	if (new_length > len)
		new_length = len;
	substr = malloc((new_length + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[new_length] = 0;
	while (new_length--)
		substr[new_length] = s[start + new_length];
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
