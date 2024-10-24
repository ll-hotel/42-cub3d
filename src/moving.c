/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:38:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/21 17:14:52 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "vec2f.h"
#include "mlx.h"
#include <math.h>

static void	turn_player(t_cube *cube, t_player *player);
static void	walk_player(t_cube *cube, t_player *player);
static void	strafe_player(t_cube *cube, t_player *player);

void	move_player(t_cube *cube, t_player *player)
{
	if (player->turning != 0)
		turn_player(cube, player);
	if (player->walking != 0)
		walk_player(cube, player);
	if (player->strafing != 0)
		strafe_player(cube, player);
}

void	rotation(t_player *player, float coef)
{
	float	cam_x;
	float	cam_y;

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

void	turn_player(t_cube *cube, t_player *player)
{
	float	coef;
	int		new_x;
	int		new_y;

	coef = 0;
	if (cube->player.use_pointer)
	{
		mlx_mouse_get_pos(cube->mlx.ptr, cube->mlx.win, &new_x, &new_y);
		coef = (player->mouse.x - new_x) / 500;
		if (new_x > SCREEN_WIDTH || new_x < 5 || new_y > SCREEN_HEIGHT
			|| new_y < 5)
		{
			mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, SCREEN_WIDTH / 2,
				SCREEN_HEIGHT / 2);
			player->mouse.x = SCREEN_WIDTH / 2;
			player->mouse.y = SCREEN_HEIGHT / 2;
		}
		else
		{
			player->mouse.x = new_x;
			player->mouse.y = new_y;
		}
	}
	else if (!cube->player.use_pointer)
		coef = 0.2 * player->turning;
	rotation(player, coef);
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
	collision_correction(cube, player, &step);
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
	collision_correction(cube, player, &step);
	player->pos = vec2f_add(step, player->pos);
}
