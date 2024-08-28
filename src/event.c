/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:19:32 by omougel           #+#    #+#             */
/*   Updated: 2024/08/27 17:31:59 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

void		update_player_dir(t_player *player);
void		update_player_pos(t_cube *cube);
static int	keypress_hook(int keysym, t_cube *cube);
static int	keyrelease_hook(int keysym, t_cube *cube);
static int	loop_hook(t_cube *cube);

void	cube_loop(t_cube *cube)
{
	mlx_do_sync(cube->mlx.ptr);
	mlx_do_key_autorepeaton(cube->mlx.ptr);
	mlx_loop_hook(cube->mlx.ptr, loop_hook, cube);
	mlx_hook(cube->mlx.win, KeyPress, KeyPressMask, keypress_hook, cube);
	mlx_hook(cube->mlx.win, KeyRelease, KeyReleaseMask, keyrelease_hook, cube);
	mlx_hook(cube->mlx.win, DestroyNotify, 0, mlx_loop_end, cube->mlx.ptr);
	mlx_loop(cube->mlx.ptr);
}

static int	keypress_hook(int keysym, t_cube *cube)
{
	if (keysym == XK_Escape)
		return (mlx_loop_end(cube->mlx.ptr));
	if (keysym == 'a' || keysym == 'd')
		cube->player.turning = (keysym == 'a') - (keysym == 'd');
	else if (keysym == 'w' || keysym == 's')
		cube->player.walking = (keysym == 'w') - (keysym == 's');
	return (0);
}

static int	loop_hook(t_cube *cube)
{
	if (cube->player.turning)
		update_player_dir(&cube->player);
	if (cube->player.walking)
		update_player_pos(cube);
	if (cube->player.walking || cube->player.turning)
		cube_render(cube);
	usleep(50000);
	return (0);
}

static int	keyrelease_hook(int keysym, t_cube *cube)
{
	if (keysym == 'a' || keysym == 'd')
		cube->player.turning = 0;
	else if (keysym == 'w' || keysym == 's')
		cube->player.walking = 0;
	return (0);
}
