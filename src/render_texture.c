/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:33:16 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/23 13:51:28 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "img_put_pixel.h"
#include <math.h>

static t_img	*find_texture(t_cube *cube, t_hitside side);
static int		find_tex_x(t_ray *ray, t_cube *cube, t_img *texture);

void	render_texture(t_ray *ray, t_cube *cube, int x)
{
	t_img *const	texture = find_texture(cube, ray->side);
	float const		y_ratio = (float)texture->height / ray->wall_height;
	int const		tex_x = find_tex_x(ray, cube, texture);
	float			y_pos_in_wall;
	int				y;

	y_pos_in_wall = ft_max(0, ray->wall_height - SCREEN_HEIGHT) * y_ratio * 0.5;
	if (ray->perpwalldist > 32)
	{
		img_put_rect(&cube->mlx.img, point(x, ray->drawstart), \
				point(x + RAY_WIDTH, ray->drawend), 0x888888);
		return ;
	}
	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		img_put_pixel(&cube->mlx.img, y, x, \
				img_get_pixel(texture, floorf(y_pos_in_wall), tex_x));
		y_pos_in_wall += y_ratio;
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
	return (&cube->we_texture);
}

static int	find_tex_x(t_ray *ray, t_cube *cube, t_img *texture)
{
	float	wall_x;
	int		tex_x;

	if (ray->side == EAST || ray->side == WEST)
		wall_x = (cube->player.pos.y - ray->perpwalldist * ray->dir.y);
	else
		wall_x = (cube->player.pos.x - ray->perpwalldist * ray->dir.x);
	wall_x = ft_absf(wall_x);
	wall_x -= floorf(wall_x);
	if (ray->side == NORTH || ray->side == EAST)
		wall_x = 1.f - wall_x;
	tex_x = floorf(wall_x * texture->width);
	if (ray->side == EAST || ray->side == WEST)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
