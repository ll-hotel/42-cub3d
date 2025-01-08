/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:52:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/07 19:29:52 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dprintf.h"
#include "parsing.h"
#include "s_map.h"
#include <stddef.h>

static int	are_values_nice(size_t y, size_t x, _Bool found_player, int cell);

int	map_has_nice_values(const t_map *map)
{
	const t_fptr	*block;
	size_t			y;
	size_t			x;
	_Bool			found_player;

	found_player = 0;
	y = -1;
	while (++y < map->height)
	{
		block = &map->blocks[y];
		x = -1;
		while (++x < block->size)
		{
			if (!are_values_nice(y, x, found_player, block->data[x]))
				return (0);
			found_player |= cell_is_player(block->data[x]);
		}
	}
	if (!found_player)
	{
		ft_dprintf(2, "Error\nCannot find player\n");
		return (0);
	}
	return (1);
}

static int	are_values_nice(size_t y, size_t x, _Bool found_player, int cell)
{
	if (!cell_is_valid(cell))
	{
		ft_dprintf(2, "Error\nInvalid grid cell `%c' (ASCII=%u) " \
				"at pos y=%u,x=%u\n", cell, cell, y, x);
		return (0);
	}
	if (cell_is_player(cell) && found_player)
	{
		ft_dprintf(2, "Error\nDuplicate player %c "\
				"at pos y=%u,x=%u\n", cell, y, x);
		return (0);
	}
	return (1);
}

int	cell_is_valid(int c)
{
	return (c == ' ' || c == '0' || c == '1' || cell_is_player(c));
}

int	cell_is_player(int c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}
