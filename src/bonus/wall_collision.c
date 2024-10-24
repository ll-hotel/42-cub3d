/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:30 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/21 17:14:08 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

void	collision_correction(t_cube *cube, t_player *player, t_vec2f *step)
{
	long const	y = floorf(player->pos.y + step->y);
	long const	x = floorf(player->pos.x + step->x);
	float		dist[4];

	dist[0] = player->pos.y + step->y - y;
	dist[1] = 1.f - dist[0];
	dist[2] = player->pos.x + step->x - x;
	dist[3] = 1.f - dist[2];
	if (y < 1 || y + 1 >= cube->map.height)
		step->y = 0;
	else if (dist[0] < 0.2f && cube->map.cells[y - 1][x] == WALL)
		step->y += 0.2f - dist[0];
	else if (dist[1] < 0.2f && cube->map.cells[y + 1][x] == WALL)
		step->y -= 0.2f - dist[1];
	if (x < 1 || x + 1 >= cube->map.width)
		step->x = 0;
	else if (dist[2] < 0.2f && cube->map.cells[y][x - 1] == WALL)
		step->x += 0.2f - dist[2];
	else if (dist[3] < 0.2f && cube->map.cells[y][x + 1] == WALL)
		step->x -= 0.2f - dist[3];
}
