/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:52:05 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 16:28:05 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void		gnl_memcpy(void *dest, void *src, u_long size);
void		*gnl_realloc(void *p, u_long old_size, u_long size);
u_long		gnl_strichr(char *str, int c);

static char	*read_next_block(int fd, char *buffer, char *line, u_long *len);
static void	__bzero(char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1] = {0};
	char		*line;
	u_long		line_len;

	if (read(fd, NULL, 0) < 0)
	{
		__bzero(buffer[fd]);
		return (NULL);
	}
	line_len = 0;
	line = read_next_block(fd, buffer[fd], NULL, &line_len);
	while (line && !line[gnl_strichr(line, '\n')])
		line = read_next_block(fd, buffer[fd], line, &line_len);
	return (line);
}

static char	*read_next_block(int fd, char *buffer, char *line, u_long *len)
{
	u_long	nl_i;
	_Bool	eol;

	if (line && read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		free(line);
		__bzero(buffer);
		return (NULL);
	}
	nl_i = gnl_strichr(buffer, '\n');
	eol = buffer[nl_i] == '\n';
	line = gnl_realloc(line, *len, *len + nl_i + eol + 1);
	if (!line)
	{
		__bzero(buffer);
		return (NULL);
	}
	gnl_memcpy(line + *len, buffer, nl_i + eol);
	gnl_memcpy(buffer, buffer + nl_i + eol, BUFFER_SIZE + 1 - nl_i);
	*len += nl_i + eol;
	line[*len] = 0;
	return (line);
}

static void	__bzero(char *buffer)
{
	u_long	i;

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
}
