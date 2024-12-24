/* ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:37:03 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 01:47:33 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/

#include "cub3D.h"
#include "mlx.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <X11/keysym.h>

#define FPS 30

void	loop_hook(struct s_cub *cub)
{
	static size_t			last;
	static size_t			now;
	static struct timeval	tv;
	static struct timeval	tv_old;

	gettimeofday(&tv, 0);
	now = tv.tv_usec / 1000;
	now /= (1000. / FPS);
	now %= FPS;
	if (now != last)
	{
		mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr, \
				cub->mlx.win_img.img_ptr, 0, 0);
		printf("%lu : %ld\n", tv.tv_sec - tv_old.tv_sec, \
				((ssize_t)(tv.tv_usec - tv_old.tv_usec) / 1000) % FPS);
		last = now;
		tv_old = tv;
	}
	else
		usleep(100);
}

void	key_hook(int keysym, struct s_cub *cub)
{
	if (keysym == XK_Escape)
		mlx_loop_end(cub->mlx.mlx_ptr);
}
