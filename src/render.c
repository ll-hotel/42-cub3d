/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:12 by omougel           #+#    #+#             */
/*   Updated: 2024/08/27 16:30:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "img_put_pixel.h"
#include <math.h>

static void		render_column(t_ray *ray, t_cube *cube, int x);
// static void		render_texture(t_ray *ray, t_cube *cube, t_img *texture, int x);
// static t_img	*find_texture(t_cube *cube, t_hitside side);
// static int		init_tex_x(t_ray *ray, t_cube *cube, t_img *texture);

void	cube_render(t_cube *cube)
{
	int			x;
	t_ray		ray;

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
	//render_texture(ray, cube, find_texture(cube, ray->side), x);
	img_put_rect(&cube->mlx.img, point(x, ray->drawstart), \
			  point(x + RAY_WIDTH, ray->drawend), \
			  0x0f0f0f * (ray->side + 1) * 4);
	img_put_rect(&cube->mlx.img, point(x, ray->drawend), \
			  point(x + RAY_WIDTH, SCREEN_HEIGHT), cube->f_colour);
}

 // static t_img	*find_texture(t_cube *cube, t_hitside side)
 // {
 // 	if (side == NORTH)
 // 		return (&cube->no_texture);
 // 	if (side == SOUTH)
 // 		return (&cube->so_texture);
 // 	if (side == EAST)
 // 		return (&cube->ea_texture);
 // 	if (side == WEST)
 // 		return (&cube->we_texture);
 // 	return (&cube->mlx.img);
 // }
 //
 // static void	render_texture(t_ray *ray, t_cube *cube, t_img *texture, int x)
 // {
 // 	const float	step = texture->height / \
 // 		(float)(SCREEN_HEIGHT / ray->perpwalldist);
 // 	float		texpos;
 // 	int			tex_x;
 // 	int			y;
 //
 // 	texpos = (ray->drawstart - SCREEN_HEIGHT / 2.f + \
 // 		(SCREEN_HEIGHT / ray->perpwalldist) / 2) * step;
 // 	tex_x = init_tex_x(ray, cube, texture);
 // 	while (tab[1]-- > 0)
 // 	{
 // 		y = ray->drawstart;
 // 		while (y < ray->drawend)
 // 		{
 // 			texpos += step;
 // 			img_put_pixel(&cube->mlx.img, y, x, \
 // 				 img_get_pixel(texture, y - ray->drawstart, tex_x));
 // 			y++;
 // 		}
 // 		tex_x += 1;
 // 		tab[0] += 1;
 // 	}
 // }
 //
 // static int	init_tex_x(t_ray *ray, t_cube *cube, t_img *texture)
 // {
 // 	float	wall_x;
 // 	int		tex_x;
 //
 // 	if (ray->side == WEST || ray->side == EAST)
 // 		wall_x = cube->player.pos.y + ray->perpwalldist * ray->dir.y;
 // 	else
 // 		wall_x = cube->player.pos.x + ray->perpwalldist * ray->dir.x;
 // 	wall_x -= floor(wall_x);
 // 	tex_x = (int)(wall_x * texture->width); // ca commence a devenir obscure bien relire les explications pour cette partie la
 // 	if (ray->side == EAST || ray->side == SOUTH)
 // 		tex_x = texture->width - tex_x - 1;
 // 	return (tex_x);
 // }
