/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_stretch_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:28:27 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/29 23:55:30 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static int	find_max_len(char **grid);
static int	resize_to_max_len(char **grid, int max_len);

int	grid_stretch_lines(char **grid)
{
	return (resize_to_max_len(grid, find_max_len(grid)));
}

static int	find_max_len(char **grid)
{
	u_long	i;
	int		max_len;
	int		len;

	max_len = 0;
	i = -1;
	while (grid[++i])
	{
		len = ft_strlen(grid[i]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}

static int	resize_to_max_len(char **grid, int max_len)
{
	u_long	i;
	int		len;
	char	*tmp;

	i = -1;
	while (grid[++i])
	{
		len = ft_strlen(grid[i]);
		if (len == max_len)
			continue ;
		tmp = ft_realloc(grid[i], len, max_len + 1);
		if (!tmp)
			return (cube_error("Malloc failed\n"));
		ft_memset(tmp + len, EMPTY, max_len - len);
		grid[i] = tmp;
		grid[i][max_len] = 0;
	}
	return (1);
}
