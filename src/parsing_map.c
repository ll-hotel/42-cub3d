/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:36:00 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/27 17:35:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"

int			cell_is_player(int c);
static int	store_map_grid(t_cube *cube, char **grid);
static int	store_player(t_cube *cube, char **grid);

int	parsing_map(t_cube *cube, char **lines)
{
	char	**grid;
	char	cell;

	(void)cube;
	grid = lines;
	cell = grid[0][0];
	while (*grid && cell != EMPTY && cell != FLOOR && cell != WALL)
	{
		grid += 1;
		cell = grid[0][0];
	}
	if (!grid)
		return (cube_error("Could not find any map grid\n"));
	if (!grid_values_check(grid))
		return (0);
	if (!grid_stretch_lines(grid))
		return (0);
	if (!grid_wall_check(grid))
		return (0);
	store_player(cube, grid);
	return (store_map_grid(cube, grid));
}

static int	store_player(t_cube *cube, char **grid)
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
	cube->player.pos.x = x;
	cube->player.pos.y = y;
	if (grid[y][x] == 'E')
		cube->player.axis = 0;
	else if (grid[y][x] == 'N')
		cube->player.axis = PI * 0.5;
	else if (grid[y][x] == 'W')
		cube->player.axis = PI;
	else if (grid[y][x] == 'S')
		cube->player.axis = PI * 1.5;
	grid[y][x] = FLOOR;
	return (1);
}

static int	store_map_grid(t_cube *cube, char **grid)
{
	u_long	grid_size;
	int		len;

	grid_size = 0;
	while (grid[grid_size])
		grid_size += 1;
	cube->map.cells = ft_calloc(grid_size, sizeof(*cube->map.cells));
	if (!cube->map.cells)
		return (cube_error("Malloc failed\n"));
	cube->map.height = grid_size;
	cube->map.width = 0;
	while (grid_size-- > 0)
	{
		cube->map.cells[grid_size] = grid[grid_size];
		len = ft_strlen(grid[grid_size]);
		if (len > cube->map.width)
			cube->map.width = len;
		grid[grid_size] = 0;
	}
	return (1);
}
