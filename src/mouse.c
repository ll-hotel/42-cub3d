/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:30:39 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/25 15:11:20 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_handler(int button, int x, int y, t_cube *cube)
{
	(void)button;
	(void)x;
	(void)y;
	(void)cube;
	return (0);
}

float	turn_with_mouse(t_cube *cube, t_player *player)
{
	(void)cube;
	player->use_pointer = false;
	return (0);
}
