/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:43 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:24:19 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft/ft_dprintf.h"
#include <stddef.h>
#define EMPTY ' '
#define WALL '1'
#define FLOOR '0'

static int	are_walls_nice(const t_map *map, size_t y, size_t x);

int	map_has_nice_walls(const t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->blocks[y].size)
			if (!are_walls_nice(map, y, x++))
				return (0);
		y += 1;
	}
	return (1);
}

static int	are_walls_nice(const t_map *map, size_t y, size_t x)
{
	const char	*errors[] = {"on a map edge", "adjacent to empty cell"};
	const char	cell = map->blocks[y].data[x];
	int			error;

	error = 0;
	if (cell != FLOOR && !cell_is_player(cell))
		return (1);
	else if (y == 0 || x == 0 || y >= map->height || x >= map->blocks[y].size)
		error = 1;
	else if (map->blocks[y].data[x - 1] == EMPTY \
			|| map->blocks[y].data[x + 1] == EMPTY \
			|| map->blocks[y - 1].data[x] == EMPTY \
			|| map->blocks[y + 1].data[x] == EMPTY)
		error = 2;
	if (error)
	{
		ft_dprintf(2, "Error\nFloor/player cell %s at y=%u,x=%u\n", \
				errors[error - 1], y, x);
		return (0);
	}
	return (1);
}
