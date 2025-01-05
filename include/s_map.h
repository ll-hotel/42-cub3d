/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:09:18 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:09:18 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H
# include <stddef.h>

typedef unsigned char	t_uchar;

typedef struct s_fptr
{
	t_uchar	*data;
	size_t	size;
}	t_fptr;

typedef struct s_map
{
	t_fptr	*blocks;
	size_t	height;
	size_t	max_width;
}	t_map;

int		s_map_init(t_map *map, const char *const *grid);
void	s_map_destroy(t_map *map);

#endif /* ifndef S_MAP_H */
