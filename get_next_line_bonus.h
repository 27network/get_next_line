/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:56:16 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/16 04:42:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	8192
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char	*inner;
	size_t	size;
	int		finished;
}	t_gnl;

/**
 * @brief Get the next line from a file descriptor.
 *
 * @param fd		File descriptor to read from.
 *
 * @return char*	The line that has been read.
 * @return NULL		If an error occurs.
 */
char	*get_next_line(int fd);

/* ************************************************************************** */
/*                                                                            */
/*		                    		UTILS                                     */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif // GET_NEXT_LINE_BONUS_H
