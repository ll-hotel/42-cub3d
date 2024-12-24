/* ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:19:51 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 12:30:45 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/

#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "s_map.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int	s_fptr_init(t_fptr *fptr, size_t size)
{
	fptr->data = malloc(size);
	if (!fptr->data)
		return (1);
	fptr->size = size;
	return (0);
}

int	s_map_init(t_map *map, const char **grid)
{
	size_t	height;

	height = 0;
	while (grid[height] != NULL)
		height += 1;
	map->blocks = ft_calloc(height + 1, sizeof(*map->blocks));
	if (!map->blocks)
		return (ft_dprintf(2, "Error\n%s\n", strerror(errno)), 1);
	map->height = height;
	height = 0;
	map->max_width = 0;
	while (height < map->height)
	{
		map->blocks[height] = (t_fptr){(void *)grid[height], strlen(grid[height])};
		if (map->blocks[height].size > map->max_width)
			map->max_width = map->blocks[height].size;
	}
	free(grid);
	return (0);
}

void	s_map_destroy(t_map *map)
{
	if (map->blocks)
	{
		while (map->height > 0)
		{
			map->height -= 1;
			free(map->blocks[map->height].data);
		}
		free(map->blocks);
	}
	ft_bzero(map, sizeof(*map));
}
