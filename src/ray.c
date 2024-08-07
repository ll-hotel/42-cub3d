/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:08:58 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/06 01:33:55 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

static void	ray_take_step(t_ray *ray, int *map_x, int *map_y);

void	ray_init_dda(t_ray *ray, t_player *player, int x)
{
	const float	plane_x = 2 * x / (float)SCREEN_WIDTH - 1.f;
	t_vec2		ray_dir_sq;

	ray->ray_dir.x = player->dir.x + player->camera.x * plane_x;
	ray->ray_dir.y = player->dir.y + player->camera.y * plane_x;
	ray_dir_sq.x = ray->ray_dir.x * ray->ray_dir.x;
	ray_dir_sq.y = ray->ray_dir.y * ray->ray_dir.y;
	ray->deltadist.x = sqrt(1. + (ray_dir_sq.y / ray_dir_sq.x));
	ray->deltadist.y = sqrt(1. + (ray_dir_sq.x / ray_dir_sq.y));
	ray->step.x = (ray->ray_dir.x < 0) - (ray->ray_dir.x >= 0);
	ray->step.y = (ray->ray_dir.y < 0) - (ray->ray_dir.y >= 0);
	if (ray->ray_dir.x >= 0)
		ray->side_dist.x = (player->pos.x - (int)player->pos.x) \
			* ray->deltadist.x;
	else
		ray->side_dist.x = ((int)player->pos.x + 1 - player->pos.x) \
			* ray->deltadist.x;
	if (ray->ray_dir.y >= 0)
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
	line_height = (SCREEN_HEIGHT / ray->perpwalldist);
	ray->drawstart = (SCREEN_HEIGHT - line_height) / 2;// - player.dirZ;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (SCREEN_HEIGHT + line_height) / 2;// - player.dirZ;
	if (ray->drawend >= SCREEN_HEIGHT)
		ray->drawend = SCREEN_HEIGHT - 1;
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
