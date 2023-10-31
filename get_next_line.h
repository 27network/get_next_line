/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 05:43:25 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/18 16:48:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	int		fd;
	int		buffer_size;
	int		last_read;
	char	*buffer;
}	t_gnl;

/**
 * @brief	Returns a line read from a file descriptor.
 *
 * @param	fd		File descriptor to read from.
 *
 * @return	char*	The line that was read.
 */
char	*get_next_line(int fd);

/**
 * @brief	Reallocates a buffer to a new size.
 *
 * @param	buffer		Pointer to the buffer to reallocate.
 * @param	old_size	Old size of the buffer.
 * @param	new_size	New size of the buffer.
 *
 * @return	char*		Pointer to the new buffer.
 */
char	*ft_realloc(char *buffer, size_t old_size, size_t new_size);

#endif // GET_NEXT_LINE_H
