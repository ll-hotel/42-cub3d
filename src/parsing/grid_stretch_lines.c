/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_stretch_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:28:27 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 16:16:51 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptr.h"
#include "parsing.h"
#include "ft_basics.h"
#include "ft_dprintf.h"
#include <errno.h>
#include <string.h>

static int	resize_to_max_len(char **grid, int max_len);

int	grid_stretch_lines(char **grid)
{
	u_long	i;
	int		max_len;

	max_len = 0;
	i = -1;
	while (grid[++i])
		max_len = ft_max(max_len, ft_strlen(grid[i]));
	return (resize_to_max_len(grid, max_len));
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
		{
			ft_dprintf(2, "Error\n%s\n", strerror(errno));
			return (0);
		}
		ft_memset(tmp + len, EMPTY, max_len - len);
		grid[i] = tmp;
		grid[i][max_len] = 0;
	}
	return (1);
}
