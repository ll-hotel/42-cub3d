/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:36:00 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:25:15 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "parsing.h"
#include "s_cub.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static char	**create_grid_from_lines(t_line *lines);
static int	store_player(t_entity *player, char **grid);

int	parsing_map(t_map *map, t_entity *player, t_line *lines)
{
	char **const	grid = create_grid_from_lines(lines);

	if (!grid)
		return (1);
	if (s_map_init(map, (const void *)grid))
		return (1);
	if (!map_has_nice_values(map) || !map_has_nice_walls(map))
		return (1);
	store_player(player, grid);
	free(grid);
	return (0);
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
