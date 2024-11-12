/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:30:39 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/25 15:08:25 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	mouse_handler(int button, int x, int y, t_cube *cube)
{
	if (!cube->player.use_pointer && button == Button1)
	{
		mlx_mouse_hide(cube->mlx.ptr, cube->mlx.win);
		cube->player.use_pointer = true;
	}
	if (cube->player.use_pointer)
	{
		cube->player.turning = 1;
		cube->player.mouse.x = x;
		cube->player.mouse.y = y;
		if (button == Button3)
		{
			mlx_mouse_show(cube->mlx.ptr, cube->mlx.win);
			cube->player.use_pointer = false;
			cube->player.turning = 0;
		}
	}
	return (0);
}

float	turn_with_mouse(t_cube *cube, t_player *player)
{
	int		new_mouse_x;
	int		new_mouse_y;
	float	coef;

	mlx_mouse_get_pos(cube->mlx.ptr, cube->mlx.win, &new_mouse_x, &new_mouse_y);
	coef = (player->mouse.x - new_mouse_x) * 0.002;
	if (new_mouse_x < SCREEN_WIDTH * 0.20 || new_mouse_x > SCREEN_WIDTH * 0.80)
	{
		mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, \
				SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		new_mouse_x = SCREEN_WIDTH / 2;
	}
	if (new_mouse_y < SCREEN_HEIGHT * 0.4 || new_mouse_y > SCREEN_HEIGHT * 0.6)
	{
		mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, \
				new_mouse_x, SCREEN_HEIGHT / 2);
		new_mouse_y = SCREEN_HEIGHT / 2;
	}
	player->mouse.x = new_mouse_x;
	player->mouse.y = new_mouse_y;
	return (coef);
}
