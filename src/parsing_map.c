/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:36:00 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/11/12 16:58:21 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_ptr.h"
#include "parsing.h"
#include "ft_basics.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int			cell_is_player(int c);
static char	**create_grid_from_lines(t_line *lines);
static int	store_map_grid(t_cube *cube, char **grid);
static int	store_player(t_cube *cube, char **grid);

int	parsing_map(t_cube *cube, t_line *lines)
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
	store_player(cube, grid);
	return (store_map_grid(cube, grid));
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

static int	store_player(t_cube *cube, char **grid)
{
	ulong	y;
	ulong	x;

	y = -1;
	x = 0;
	while (grid[++y])
	{
		x = 0;
		while (grid[y][x] && !cell_is_player(grid[y][x]))
			x += 1;
		if (cell_is_player(grid[y][x]))
			break ;
	}
	cube->player.pos.x = x + 0.5;
	cube->player.pos.y = y + 0.5;
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

	grid_size = 0;
	while (grid[grid_size] != NULL)
		grid_size += 1;
	cube->map.cells = ft_calloc(grid_size + 1, sizeof(*cube->map.cells));
	if (!cube->map.cells)
		return (ft_dprintf(2, "Error\n%s\n", strerror(errno)), 0);
	cube->map.height = grid_size;
	cube->map.width = ft_strlen(grid[0]);
	while (grid_size-- > 0)
		cube->map.cells[grid_size] = grid[grid_size];
	free(grid);
	return (1);
}
