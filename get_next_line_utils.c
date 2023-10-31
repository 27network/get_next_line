/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 05:46:57 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/18 16:44:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_realloc(char *buffer, size_t old_size, size_t new_size)
{
	char	*new_buffer;
	size_t	i;

	new_buffer = malloc(sizeof(char) * new_size);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (i < new_size)
		new_buffer[i++] = 0;
	if (buffer)
	{
		i = 0;
		while (i < old_size && i < new_size)
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		free(buffer);
	}
	return (new_buffer);
}

#ifdef MAIN
int	main(int argc, char *argv[])
{
	char	*file_name;
	int		fd;
	char	*line;

	if (argc == 2)
	{
		file_name = argv[1];
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			printf("Error: Failed to open file \"%s\".\n", file_name);
			return (1);
		}
		printf("Buffer size: %d\n", BUFFER_SIZE);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			printf("%s", line);
			free(line);
		}
	}
	return (0);
}
#endif
