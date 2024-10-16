/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:38:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/16 16:40:53 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "vec2f.h"
#include <math.h>

static void	turn_player(t_player *player);
static void	walk_player(t_cube *cube, t_player *player);
static void	strafe_player(t_cube *cube, t_player *player);

static void	adjust_step(t_cube *cube, t_player *player, t_vec2f *step);

void	move_player(t_cube *cube, t_player *player)
{
	if (player->turning != 0)
		turn_player(player);
	if (player->walking != 0)
		walk_player(cube, player);
	if (player->strafing != 0)
		strafe_player(cube, player);
}

void	turn_player(t_player *player)
{
	float	coef;
	float	cam_x;
	float	cam_y;

	coef = 0.2 * player->turning;
	player->axis += coef;
	if (player->axis < 0)
		player->axis += 2.f * PI;
	else if (player->axis > 2.f * PI)
		player->axis -= 2.f * PI;
	player->dir.x = cosf(player->axis);
	player->dir.y = -sinf(player->axis);
	cam_x = player->camera.x;
	cam_y = player->camera.y;
	player->camera.x = cam_x * cosf(coef) + cam_y * sinf(coef);
	player->camera.y = cam_x * -sinf(coef) + cam_y * cosf(coef);
}

void	walk_player(t_cube *cube, t_player *player)
{
	t_vec2f	step;
	float	axis;

	axis = player->axis + PI * (player->walking == -1);
	if (axis > 2 * PI)
		axis -= 2 * PI;
	else if (axis < 0)
		axis += 2 * PI;
	step = vec2f_scal(vec2f(cosf(axis), -sinf(axis)), 0.1f);
	adjust_step(cube, player, &step);
	player->pos = vec2f_add(step, player->pos);
}

void	strafe_player(t_cube *cube, t_player *player)
{
	t_vec2f	step;
	float	axis;

	axis = player->axis + PI * 0.5 * player->strafing;
	if (axis > 2 * PI)
		axis -= 2 * PI;
	else if (axis < 0)
		axis += 2 * PI;
	step = vec2f_scal(vec2f(cosf(axis), -sinf(axis)), 0.1f);
	adjust_step(cube, player, &step);
	player->pos = vec2f_add(step, player->pos);
}

static void	adjust_step(t_cube *cube, t_player *player, t_vec2f *step)
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
