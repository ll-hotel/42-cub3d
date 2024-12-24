/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 19:38:09 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft/ft_dprintf.h"
#include <fcntl.h>
#include <unistd.h>

int	cub_parse_file(t_cub *cub, const char *filename)
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
		error = !parsing_textures(cub, lines);
	if (!error)
		error = !parsing_colours(cub, lines);
	if (!error)
		error = !parsing_map(cub, lines);
	if (lines)
		free_lines(lines);
	return (error == 0);
}
