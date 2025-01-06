/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/05 22:50:50 by ll-hotel         ###   ########.fr       */
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
		return (1);
	}
	lines = NULL;
	error = !read_file(filename, &lines);
	ft_dprintf(1, "Next...\n");
	if (!error)
		error = !parsing_textures(cub->textures, cub->mlx.mlx_ptr, lines);
	ft_dprintf(1, "Next...\n");
	if (!error)
		error = !parsing_colours(cub->colors, lines);
	ft_dprintf(1, "Next...\n");
	if (!error)
		error = !parsing_map(&cub->map, &cub->player, lines);
	ft_dprintf(1, "Next...\n");
	if (lines)
		free_lines(lines);
	return (error);
}
