/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:36:00 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 12:36:41 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "libft/ptr.h"
#include "parsing.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int			cell_is_player(int c);
static char	**create_grid_from_lines(t_line *lines);
static int	store_player(t_entity *player, char **grid);

int	parsing_map(t_cub *cub, t_line *lines)
{
	char	**grid;

	grid = create_grid_from_lines(lines);
	if (grid == NULL)
		return (0);
	if (!grid_values_check(grid) || \
			!grid_stretch_lines(grid) || \
			!grid_wall_check(grid))
	{
		ft_free2((void **)grid, free);
		return (0);
	}
	store_player(&cub->player, grid);
	return (s_map_init(&cub->map, (const void *)grid));
}

static char	**create_grid_from_lines(t_line *lines)
{
	char	**grid;
	int		size;
	int		i;

	i = -1;
	while (lines[++i].ptr && !ft_isdigit(lines[i].key[0]))
		if (lines[i].key[0] != 0 && ft_strcmp(lines[i].key, "NO") && \
				ft_strcmp(lines[i].key, "SO") && ft_strcmp(lines[i].key, "EA") \
				&& ft_strcmp(lines[i].key, "WE") && \
				ft_strcmp(lines[i].key, "F") && ft_strcmp(lines[i].key, "C"))
			return (ft_dprintf(2, "Error\nUnexpected key '%s'\n", \
						lines[i].key), NULL);
	size = 0;
	while (lines[i + size].ptr != NULL)
		size += 1;
	grid = ft_calloc(size + 1, sizeof(*grid));
	if (!grid)
		return (NULL);
	size = -1;
	while (lines[i + ++size].ptr != NULL)
	{
		grid[size] = lines[i + size].ptr;
		lines[i + size].ptr = NULL;
	}
	return (grid);
}

static int	store_player(t_entity *player, char **grid)
{
	ulong	y;
	ulong	x;

	y = -1;
	while (grid[++y])
	{
		x = 0;
		while (grid[y][x] && !cell_is_player(grid[y][x]))
			x += 1;
		if (cell_is_player(grid[y][x]))
			break ;
	}
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	if (grid[y][x] == 'E')
		player->axis = 0;
	else if (grid[y][x] == 'N')
		player->axis = M_PI * 1.5;
	else if (grid[y][x] == 'W')
		player->axis = M_PI;
	else if (grid[y][x] == 'S')
		player->axis = M_PI * 0.5;
	grid[y][x] = BL_FLOOR;
	return (1);
}
