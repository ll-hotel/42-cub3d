/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_wall_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:43 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 16:21:10 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_dprintf.h"

int			cell_is_valid(int c);
int			cell_is_player(int c);
static int	check_walls(char **grid, u_long y, u_long x);

int	grid_wall_check(char **grid)
{
	u_long	y;
	u_long	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			if (!check_walls(grid, y, x++))
				return (0);
		y += 1;
	}
	return (1);
}

static int	check_walls(char **grid, u_long y, u_long x)
{
	const char	*errors[] = {"on a map edge", "adjacent to empty cell"};
	const char	cell = grid[y][x];
	int			error;

	error = 0;
	if (cell != FLOOR && !cell_is_player(cell))
		return (1);
	else if (y == 0 || x == 0 || !grid[y + 1] || !grid[y][x + 1])
		error = 1;
	else if (grid[y][x - 1] == EMPTY || grid[y][x + 1] == EMPTY || \
			grid[y - 1][x] == EMPTY || grid[y + 1][x] == EMPTY)
		error = 2;
	if (error)
	{
		ft_dprintf(2, "Error\nFloor/player cell %s at y=%u,x=%u\n", \
				errors[error - 1], y, x);
		return (0);
	}
	return (1);
}
