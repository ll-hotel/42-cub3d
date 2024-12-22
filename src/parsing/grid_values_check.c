/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_values_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:52:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/18 18:00:19 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "parsing.h"

int			cell_is_valid(int c);
int			cell_is_player(int c);
static int	check_cell_value(u_long y, u_long x, char found_player, int cell);

int	grid_values_check(char **grid)
{
	u_long	y;
	u_long	x;
	char	found_player;

	found_player = 0;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (!check_cell_value(y, x, found_player, grid[y][x]))
				return (0);
			found_player |= cell_is_player(grid[y][x]);
		}
	}
	if (!found_player)
	{
		ft_dprintf(2, "Error\nCannot find player\n");
		return (0);
	}
	return (1);
}

static int	check_cell_value(u_long y, u_long x, char found_player, int cell)
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
