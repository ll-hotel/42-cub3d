/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:59:03 by omougel           #+#    #+#             */
/*   Updated: 2024/07/29 15:56:07 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_mlx(t_cube cub)
{
	cub.mlx.ptr = mlx_init();
	if (cub.mlx.ptr == NULL)
		return (perror("Problem with malloc"), 0);
	cub.mlx.win = mlx_new_window(cub.mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
							  NAME);
	if (cub.mlx.win == NULL)
	{
		mlx_destroy_display(cub.mlx.ptr);
		free(cub.mlx.ptr);
		return (perror("Problem with malloc"), 0);
	}
	cub.mlx.img.ptr = mlx_new_image(cub.mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (cub.mlx.img.ptr == NULL)
	{
		mlx_destroy_window(cub.mlx.ptr, cub.mlx.win);
		mlx_destroy_display(cub.mlx.ptr);
		free(cub.mlx.ptr);
		return (perror("Problem with malloc"), 0);
	}
	cub.mlx.img.pixels = mlx_get_data_addr(cub.mlx.img.ptr, &cub.mlx.img.bpp, &cub.mlx.img.size_line, &cub.mlx.img.endian);
	return (1);
}

//maybe merge this function with another because it is really short
void  render_init(t_cube *cub)
{
	cub->player.cameraX = -0.66 * cub->player.dirY;
	cub->player.cameraY = -0.66 * cub->player.dirX;
}
