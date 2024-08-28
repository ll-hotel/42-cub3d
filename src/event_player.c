/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:38:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/27 17:44:22 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "vec2f.h"
#include <math.h>

void	update_player_dir(t_player *player)
{
	const float	coef = 0.1;
	float		cam_x;
	float		cam_y;

	if (player->turning == 0)
		return ;
	player->axis += player->turning * coef;
	if (player->axis < 0)
		player->axis += 2.f * PI;
	else if (player->axis > 2.f * PI)
		player->axis -= 2.f * PI;
	player->dir.x = cosf(player->axis);
	player->dir.y = -sinf(player->axis);
	cam_x = player->camera.x;
	cam_y = player->camera.y;
	player->camera.x = cam_x * cosf(-coef) - cam_y * sinf(-coef);
	player->camera.x = cam_x * sinf(-coef) + cam_y * cosf(-coef);
}

void	update_player_pos(t_cube *cube)
{
	t_player	*player;
	t_vec2f		next_pos;
	t_vec2f		step;

	player = &cube->player;
	step = vec2f_scal(player->dir, 0.1f);
	if (player->walking == 1)
		next_pos = vec2f_add(player->pos, step);
	else if (player->walking == -1)
		next_pos = vec2f_sub(player->pos, step);
	else
		return ;
	if (next_pos.y < 0 || next_pos.y >= cube->map.height)
		next_pos.y = player->pos.y;
	else if (next_pos.x < 0 || next_pos.x >= cube->map.width)
		next_pos.x = player->pos.x;
	else if (cube->map.cells[(int)next_pos.y][(int)next_pos.x] == WALL)
		return ;
	player->pos = next_pos;
}
