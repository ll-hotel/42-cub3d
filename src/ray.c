/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:08:58 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/21 05:53:17 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "vec2f.h"
#include <math.h>

static void	ray_take_step(t_ray *ray, int *map_x, int *map_y);

void	ray_init_dda(t_ray *ray, t_player *player, int x)
{
	const float	screen_ratio = ((2.f * x) / SCREEN_WIDTH) - 1.f;
	const int	map_x = floorf(player->pos.x);
	const int	map_y = floorf(player->pos.y);

	ray->dir.x = -player->dir.x + player->camera.x * screen_ratio;
	ray->dir.y = -player->dir.y + player->camera.y * screen_ratio;
	ray->deltadist.x = ft_absf(1.f / ray->dir.x);
	ray->deltadist.y = ft_absf(1.f / ray->dir.y);
	ray->step.x = (ray->dir.x < 0) - (ray->dir.x >= 0);
	ray->step.y = (ray->dir.y < 0) - (ray->dir.y >= 0);
	if (ray->dir.x >= 0)
		ray->side_dist.x = (player->pos.x - map_x) * ray->deltadist.x;
	else
		ray->side_dist.x = (map_x + 1 - player->pos.x) * ray->deltadist.x;
	if (ray->dir.y >= 0)
		ray->side_dist.y = (player->pos.y - map_y) * ray->deltadist.y;
	else
		ray->side_dist.y = (map_y + 1 - player->pos.y) * ray->deltadist.y;
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
	if (ray->side == EAST || ray->side == WEST)
		ray->perpwalldist = ray->side_dist.x - ray->deltadist.x;
	else
		ray->perpwalldist = ray->side_dist.y - ray->deltadist.y;
	if (ray->perpwalldist <= 0.f)
		ray->perpwalldist = 0.0000000000000000000001f;
	ray->wall_height = (SCREEN_HEIGHT / ray->perpwalldist) * 0.5f;
}

void	ray_find_drawing_limits(t_ray *ray)
{
	ray->drawstart = (SCREEN_HEIGHT - ray->wall_height) * 0.5;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = SCREEN_HEIGHT - ray->drawstart;
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
