/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 16:33:10 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_dprintf.h"
#include <fcntl.h>
#include <unistd.h>

int	cube_parse_file(t_cube *cube, const char *filename)
{
	t_line	*lines;
	int		error;

	if (!ft_str_endswith(filename, ".cub"))
	{
		ft_dprintf(2, "Error\n'%s': Wrong file extension\n", filename);
		return (0);
	}
	lines = NULL;
	error = !read_file(filename, &lines);
	if (!error)
		error = !parsing_textures(cube, lines);
	if (!error)
		error = !parsing_colours(cube, lines);
	if (!error)
		error = !parsing_map(cube, lines);
	if (lines)
		free_lines(lines);
	return (error == 0);
}
