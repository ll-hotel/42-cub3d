/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:08:58 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/27 18:05:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "vec2f.h"
#include <math.h>

static void	ray_take_step(t_ray *ray, int *map_x, int *map_y);

void	ray_init_dda(t_ray *ray, t_player *player, int x)
{
	const float	screen_ratio = 1.f - ((2.f * x) / SCREEN_WIDTH);
	t_vec2f		ray_dir_sq;

	ray->dir.x = -player->dir.x + player->camera.x * screen_ratio;
	ray->dir.y = -player->dir.y + player->camera.y * screen_ratio;
	ray_dir_sq.x = ray->dir.x * ray->dir.x;
	ray_dir_sq.y = ray->dir.y * ray->dir.y;
	ray->deltadist.x = sqrt(1. + (ray_dir_sq.y / ray_dir_sq.x));
	ray->deltadist.y = sqrt(1. + (ray_dir_sq.x / ray_dir_sq.y));
	ray->step.x = (ray->dir.x < 0) - (ray->dir.x >= 0);
	ray->step.y = (ray->dir.y < 0) - (ray->dir.y >= 0);
	if (ray->dir.x >= 0)
		ray->side_dist.x = (player->pos.x - (int)player->pos.x) \
			* ray->deltadist.x;
	else
		ray->side_dist.x = ((int)player->pos.x + 1 - player->pos.x) \
			* ray->deltadist.x;
	if (ray->dir.y >= 0)
		ray->side_dist.y = (player->pos.y - (int)player->pos.y) \
			* ray->deltadist.y;
	else
		ray->side_dist.y = ((int)player->pos.y + 1 - player->pos.y) \
			* ray->deltadist.y;
}

void	ray_perform_dda(t_ray *ray, t_cube *cube)
{
	int	hit;
	int	map_x;
	int	map_y;

	hit = 0;
	map_x = (int)cube->player.pos.x;
	map_y = (int)cube->player.pos.y;
	while (hit == 0)
	{
		ray_take_step(ray, &map_x, &map_y);
		hit = (cube->map.cells[map_y][map_x] == WALL);
	}
}

void	ray_find_drawing_limits(t_ray *ray)
{
	int	line_height;

	if (ray->side == EAST || ray->side == WEST)
		ray->perpwalldist = ray->side_dist.x - ray->deltadist.x;
	else
		ray->perpwalldist = ray->side_dist.y - ray->deltadist.y;
	if (ray->perpwalldist < 1.f)
		ray->perpwalldist = 1.f;
	line_height = (SCREEN_HEIGHT / ray->perpwalldist);
	ray->drawstart = (SCREEN_HEIGHT - line_height) / 2;// - player.dirZ;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = SCREEN_HEIGHT - ray->drawstart - 1;
}

static void	ray_take_step(t_ray *ray, int *map_x, int *map_y)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->deltadist.x;
		*map_x += ray->step.x;
		ray->side = WEST;
		if (ray->step.x > 0)
			ray->side = EAST;
	}
	else
	{
		ray->side_dist.y += ray->deltadist.y;
		*map_y += ray->step.y;
		ray->side = SOUTH;
		if (ray->step.y > 0)
			ray->side = NORTH;
	}
}
