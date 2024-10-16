/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:12 by omougel           #+#    #+#             */
/*   Updated: 2024/10/15 13:00:18 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "img_put_pixel.h"

void	cube_render(t_cube *cube)
{
	t_ray	ray;
	int		x;

	img_put_rect(&cube->mlx.img, point(0, 0), \
			point(SCREEN_WIDTH, SCREEN_HEIGHT / 2), \
			cube->c_colour);
	img_put_rect(&cube->mlx.img, point(0, SCREEN_HEIGHT / 2), \
			point(SCREEN_WIDTH, SCREEN_HEIGHT), \
			cube->f_colour);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_init_dda(&ray, &cube->player, x);
		ray_perform_dda(&ray, cube);
		ray_find_drawing_limits(&ray);
		render_texture(&ray, cube, x);
		x += RAY_WIDTH;
	}
	render_minimap(cube);
	cube_put_image(cube);
}
