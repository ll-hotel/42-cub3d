/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:12 by omougel           #+#    #+#             */
/*   Updated: 2024/08/06 01:14:21 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

static void		render_column(t_ray *ray, t_cube *cube, int x);
static void		render_texture(t_ray *ray, t_cube *cube, t_img *texture, int x);
static t_img	*find_texture(t_cube *cube, t_hitside side);
static int		init_tex_x(t_ray *ray, t_cube *cube, t_img *texture);

void	cube_render(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		ray_init_dda(&ray, &cube->player, x);
		ray_perform_dda(&ray, cube);
		ray_find_drawing_limits(&ray);
		render_column(&ray, cube, x);
	}
	cube_put_image(cube);
}

static void	render_column(t_ray *ray, t_cube *cube, int x)
{
	int	y;

	y = 0;
	while (y < ray->drawstart)
	{
		img_put_pixel(&cube->mlx.img, y, x, cube->c_colour);
		y += 1;
	}
	render_texture(ray, cube, find_texture(cube, ray->side), x);
	y = ray->drawend;
	while (y < SCREEN_HEIGHT)
	{
		img_put_pixel(&cube->mlx.img, y, x, cube->f_colour);
		y += 1;
	}
}

static t_img	*find_texture(t_cube *cube, t_hitside side)
{
	if (side == NORTH)
		return (&cube->no_texture);
	if (side == SOUTH)
		return (&cube->so_texture);
	if (side == EAST)
		return (&cube->ea_texture);
	if (side == WEST)
		return (&cube->we_texture);
	return (&cube->mlx.img);
}

static void	render_texture(t_ray *ray, t_cube *cube, t_img *texture, int x)
{
	const int	tex_x = init_tex_x(ray, cube, texture);
	const float	step = texture->height / \
		(float)(SCREEN_HEIGHT / ray->perpwalldist);
	float		texpos;
	int			y;

	texpos = (ray->drawstart - SCREEN_HEIGHT / 2.f + \
		(SCREEN_HEIGHT / ray->perpwalldist) / 2) * step;
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		texpos += step;
		img_put_pixel(&cube->mlx.img, \
				y, \
				x, \
				img_get_pixel(texture, y - ray->drawstart, tex_x));
		y++;
	}
}

static int	init_tex_x(t_ray *ray, t_cube *cube, t_img *texture)
{
	float	wall_x;
	int		tex_x;

	if (ray->side == WEST || ray->side == EAST)
		wall_x = cube->player.pos.y + ray->perpwalldist * ray->ray_dir.y;
	else
		wall_x = cube->player.pos.x + ray->perpwalldist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width); // ca commence a devenir obscure bien relire les explications pour cette partie la
	if (ray->side == EAST || ray->side == SOUTH)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
