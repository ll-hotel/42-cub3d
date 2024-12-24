/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:38:31 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 19:30:00 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "libft/get_next_line.h"
#include "libft/vec.h"
#include "parsing.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	append_line(t_vec *file, char *line);

int	read_file(char const *file_name, t_line **lines)
{
	int		fd;
	t_vec	file;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\nCould not open file %s: %s\n", \
				file_name, strerror(errno));
		return (0);
	}
	vec_new(&file, sizeof(**lines));
	line = get_next_line(fd);
	while (line)
	{
		if (!append_line(&file, line))
			return (0);
		line = get_next_line(fd);
	}
	if (!vec_addback(&file, &(t_line){0}))
		return (vec_clear(&file, free_line), 0);
	*lines = file.array;
	return (1);
}

static int	append_line(t_vec *file, char *str)
{
	t_line	line;
	char	*newline;

	newline = ft_strrchr(str, '\n');
	if (newline)
		*newline = 0;
	line_from_str(&line, str);
	if (vec_addback(file, &line) == NULL)
	{
		free(str);
		vec_clear(file, free_line);
		return (0);
	}
	return (1);
}
