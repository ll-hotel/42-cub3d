/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:09:02 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:22:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include "s_mlx.h"
#include <X11/keysym.h>
#include <sys/time.h>
#include <unistd.h>

void	loop_hook(struct s_cub *cub)
{
	s_mlx_put_image_to_window(&cub->mlx, &cub->win_img, 0, 0);
	usleep(100);
}

void	key_hook(int keysym, struct s_cub *cub)
{
	if (keysym == XK_Escape)
		mlx_loop_end(cub->mlx.mlx_ptr);
}
