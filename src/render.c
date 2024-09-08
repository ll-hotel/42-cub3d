/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:12 by omougel           #+#    #+#             */
/*   Updated: 2024/09/08 20:38:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "img_put_pixel.h"

static void	render_column(t_ray *ray, t_cube *cube, int x);

void	cube_render(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < CAMERA_PLANE_WIDTH)
	{
		ray_init_dda(&ray, &cube->player, x * RAY_WIDTH);
		ray_perform_dda(&ray, cube);
		ray_find_drawing_limits(&ray);
		render_column(&ray, cube, x * RAY_WIDTH);
		x += 1;
	}
	render_minimap(cube);
	cube_put_image(cube);
}

static void	render_column(t_ray *ray, t_cube *cube, int x)
{
	img_put_rect(&cube->mlx.img, point(x, 0), \
			point(x + RAY_WIDTH, ray->drawstart), \
			cube->c_colour);
	render_texture(ray, cube, x);
	img_put_rect(&cube->mlx.img, point(x, ray->drawend), \
			point(x + RAY_WIDTH, SCREEN_HEIGHT), cube->f_colour);
}
