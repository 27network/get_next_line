/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 05:42:15 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/18 21:45:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_next_line_length(t_gnl *gnl)
{
	int	i;

	i = -1;
	if (!gnl->buffer)
		return (-1);
	if (gnl->buffer_size == 0)
		return (0);
	while (++i < (int)gnl->buffer_size)
		if (gnl->buffer[i] == '\n')
			return (i + 1);
	return (-1);
}

static void	gnl_read(t_gnl *gnl)
{
	int		i;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	gnl->last_read = read(gnl->fd, buffer, BUFFER_SIZE);
	if (gnl->last_read > 0)
	{
		gnl->buffer = ft_realloc(gnl->buffer, gnl->buffer_size,
				gnl->buffer_size + gnl->last_read);
		if (!gnl->buffer)
			free(buffer);
		if (!gnl->buffer)
			return ;
		i = -1;
		while (++i < gnl->last_read)
			gnl->buffer[i + gnl->buffer_size] = buffer[i];
		free(buffer);
		gnl->buffer_size += gnl->last_read;
		if (gnl_next_line_length(gnl) == -1)
			gnl_read(gnl);
	}
	else
		free(buffer);
	if (gnl->last_read < 0)
		free(gnl->buffer);
}

static void	gnl_shrink_buffer(t_gnl *gnl, size_t n)
{
	char	*new_buffer;
	int		index;

	new_buffer = malloc(sizeof(char) * (gnl->buffer_size - n));
	if (!new_buffer)
		return ;
	gnl->buffer_size -= n;
	index = -1;
	while (++index < gnl->buffer_size)
		new_buffer[index] = gnl->buffer[index + n];
	free(gnl->buffer);
	gnl->buffer = new_buffer;
}

static char	*gnl_dup_line(t_gnl *gnl)
{
	int		size;
	char	*line;
	int		eof;

	size = gnl_next_line_length(gnl);
	eof = (gnl->last_read < BUFFER_SIZE);
	if (size == -1 && !eof)
		return (NULL);
	if (size == -1)
		size = gnl->buffer_size;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	line[size] = '\0';
	while (--size >= 0)
		line[size] = gnl->buffer[size];
	if (eof)
		gnl_shrink_buffer(gnl, gnl->buffer_size);
	else
		gnl_shrink_buffer(gnl, gnl_next_line_length(gnl));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl = {-1, -1, -1, NULL};

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl.fd != fd || !gnl.buffer)
	{
		gnl.fd = fd;
		if (gnl.buffer)
			free(gnl.buffer);
		gnl.buffer_size = 0;
	}
	gnl_read(&gnl);
	if (gnl.buffer_size == 0)
	{
		gnl.fd = -1;
		return (NULL);
	}
	return (gnl_dup_line(&gnl));
}
