/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tracking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:40:30 by omougel           #+#    #+#             */
/*   Updated: 2024/10/16 00:43:51 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>

int	mouse_moving(t_cube *cube)
{
	int	new_x;
	int	new_y;

	mlx_mouse_get_pos(cube->mlx.ptr, cube->mlx.win, &new_x, &new_y);
	return (new_x != cube->player.mouse.x || new_y != cube->player.mouse.y);
}
