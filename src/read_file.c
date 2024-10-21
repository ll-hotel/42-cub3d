/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:38:31 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 16:57:55 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_basics.h"
#include "ft_dprintf.h"
#include "ft_vec.h"
#include "get_next_line.h"
#include "parsing.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

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

static int	bytes_are_valid(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_isalnum(str[i]) && str[i] != ' ' && str[i] != ',')
		{
			ft_dprintf(2, "Error\nUnexpected character '%c' (%x)\n", \
					str[i], str[i]);
			return (0);
		}
		i += 1;
	}
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
	if (!bytes_are_valid(line.key))
		return (0);
	if (vec_addback(file, &line) == NULL)
	{
		free(str);
		vec_clear(file, free_line);
		return (0);
	}
	return (1);
}
