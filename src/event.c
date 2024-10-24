/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:19:32 by omougel           #+#    #+#             */
/*   Updated: 2024/10/24 13:30:25 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

extern void	move_player(t_cube *cube, t_player *player);
static int	keypress_hook(int keysym, t_cube *cube);
static int	keyrelease_hook(int keysym, t_cube *cube);
static int	loop_hook(t_cube *cube);
static int	mouse_handler(int Button, int x, int y, t_cube *cube);

void	cube_loop(t_cube *cube)
{
	mlx_do_sync(cube->mlx.ptr);
	mlx_do_key_autorepeaton(cube->mlx.ptr);
	mlx_loop_hook(cube->mlx.ptr, loop_hook, cube);
	mlx_hook(cube->mlx.win, KeyPress, KeyPressMask, keypress_hook, cube);
	mlx_hook(cube->mlx.win, KeyRelease, KeyReleaseMask, keyrelease_hook, cube);
	mlx_hook(cube->mlx.win, DestroyNotify, 0, mlx_loop_end, cube->mlx.ptr);
	mlx_mouse_hook(cube->mlx.win, mouse_handler, cube);
	mlx_loop(cube->mlx.ptr);
}

static int	mouse_handler(int Button, int x, int y, t_cube *cube)
{
	if (Button == Button1)
	{
		mlx_mouse_hide(cube->mlx.ptr, cube->mlx.win);
		cube->player.use_pointer = true;
		cube->player.turning = 1;
		cube->player.mouse.x = x;
		cube->player.mouse.y = y;
	}
	else if (Button == Button3)
	{
		mlx_mouse_show(cube->mlx.ptr, cube->mlx.win);
		cube->player.use_pointer = false;
		cube->player.turning = 0;
	}
	return (0);
}

static int	keypress_hook(int keysym, t_cube *cube)
{
	if (keysym == XK_Escape)
		return (mlx_loop_end(cube->mlx.ptr));
	else if ((keysym == XK_Left || keysym == XK_Right)
		&& !cube->player.use_pointer)
		cube->player.turning = (keysym == XK_Left) - (keysym == XK_Right);
	else if (keysym == XK_w || keysym == XK_s)
		cube->player.walking = (keysym == XK_w) - (keysym == XK_s);
	else if (keysym == 'a' || keysym == 'd')
		cube->player.strafing = (keysym == 'a') - (keysym == 'd');
	return (0);
}

static int	loop_hook(t_cube *cube)
{
	if (cube->player.moving)
	{
		move_player(cube, &cube->player);
		cube_render(cube);
	}
	return (0);
}

static int	keyrelease_hook(int keysym, t_cube *cube)
{
	if ((keysym == XK_Left || keysym == XK_Right) && !cube->player.use_pointer)
		cube->player.turning = 0;
	else if (keysym == 'w' || keysym == 's')
		cube->player.walking = 0;
	else if (keysym == 'a' || keysym == 'd')
		cube->player.strafing = 0;
	return (0);
}
