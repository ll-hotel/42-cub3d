/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/29 18:29:27 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	free_file_lines(char **lines);

int	cube_parse_file(t_cube *cube, const char *file_name)
{
	int		file_fd;
	char	**lines;
	int		error;

	if (!ft_str_endswith(file_name, ".cub"))
		return (cube_error("Wrong file extension\n"));
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
	{
		ft_dprintf(2, "Error\nCould not open file %s: %s\n", \
				file_name, strerror(errno));
		return (0);
	}
	error = !read_file(file_fd, &lines);
	close(file_fd);
	if (error)
		return (free_file_lines(lines));
	if (!parsing_textures(cube, lines))
		return (free_file_lines(lines));
	if (!parsing_colours(cube, lines))
		return (free_file_lines(lines));
	if (!parsing_map(cube, lines))
		return (free_file_lines(lines));
	free_file_lines(lines);
	return (1);
}

static int	free_file_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	return (0);
}
