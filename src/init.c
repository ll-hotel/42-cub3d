/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:59:03 by omougel           #+#    #+#             */
/*   Updated: 2024/09/21 06:03:54 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include "vec2f.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int		cube_init_mlx(t_cube *cube);
static float	sign_of(float x);

int	init_cube(t_cube *cube, const char *file_name)
{
	float const	fov = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;

	if (!cube_init_mlx(cube) || !cube_parse_file(cube, file_name))
	{
		destroy_cube(cube);
		return (0);
	}
	cube->player.dir.x = cosf(cube->player.axis);
	cube->player.dir.y = -sinf(cube->player.axis);
	if (roundf(cube->player.dir.x) == 0)
		cube->player.camera.x = fov * sign_of(cube->player.dir.y);
	else if (roundf(cube->player.dir.y) == 0)
		cube->player.camera.y = fov * sign_of(cube->player.dir.x);
	return (1);
}

static int	cube_init_mlx(t_cube *cube)
{
	cube->mlx.ptr = mlx_init();
	if (cube->mlx.ptr == NULL)
		return (perror("Problem with mlx"), 0);
	cube->mlx.win = mlx_new_window(cube->mlx.ptr, \
			SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
	if (cube->mlx.win == NULL)
		return (perror("Problem with mlx"), 0);
	cube->mlx.img.ptr = mlx_new_image(cube->mlx.ptr, \
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (cube->mlx.img.ptr == NULL)
		return (perror("Problem with mlx"), 0);
	cube->mlx.img.width = SCREEN_WIDTH;
	cube->mlx.img.height = SCREEN_HEIGHT;
	cube->mlx.img.pixels = mlx_get_data_addr(cube->mlx.img.ptr, \
			&cube->mlx.img.bpp, \
			&cube->mlx.img.size_line, \
			&cube->mlx.img.endian);
	return (1);
}

void	destroy_cube(t_cube *cube)
{
	int	i;

	if (!cube->mlx.ptr)
		return ;
	if (cube->map.cells)
	{
		i = 0;
		while (i < cube->map.height)
			free(cube->map.cells[i++]);
		free(cube->map.cells);
	}
	if (cube->no_texture.ptr)
		mlx_destroy_image(cube->mlx.ptr, cube->no_texture.ptr);
	if (cube->ea_texture.ptr)
		mlx_destroy_image(cube->mlx.ptr, cube->ea_texture.ptr);
	if (cube->so_texture.ptr)
		mlx_destroy_image(cube->mlx.ptr, cube->so_texture.ptr);
	if (cube->we_texture.ptr)
		mlx_destroy_image(cube->mlx.ptr, cube->we_texture.ptr);
	if (cube->mlx.img.ptr)
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.ptr);
	if (cube->mlx.win)
		mlx_destroy_window(cube->mlx.ptr, cube->mlx.win);
	mlx_destroy_display(cube->mlx.ptr);
	free(cube->mlx.ptr);
}

static float	sign_of(float x)
{
	return ((x >= 0.f) - (x < 0.f));
}
