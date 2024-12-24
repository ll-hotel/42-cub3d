/* ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:03:55 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 12:27:57 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/

#ifndef S_CUB_H
# define S_CUB_H
# include "s_img.h"
# include "s_map.h"
# include "s_mlx.h"

typedef unsigned int	t_uint;

typedef struct s_v2i
{
	int	x;
	int	y;
}	t_v2i;

typedef struct s_entity
{
	t_v2i	pos;
	float	axis;
	t_v2i	dir;
}	t_entity;

enum	e_texture_index
{
	TX_NORTH,
	TX_SOUTH,
	TX_EAST,
	TX_WEST,
	TX_NB,
};

enum	e_color_index
{
	CO_FLOOR,
	CO_CEILING,
	CO_NB,
};

typedef struct s_cub
{
	t_mlx		mlx;
	t_img		textures[TX_NB];
	t_uint		colors[CO_NB];
	t_entity	player;
	t_map		map;
}	t_cub;

/* s_cub.c */
int		s_cub_init(t_cub *cub);
void	s_cub_destroy(t_cub *cub);
void	s_cub_run(t_cub *cub);

#endif /* ifndef S_CUB_H */
