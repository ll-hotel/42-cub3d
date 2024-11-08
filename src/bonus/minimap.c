/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:26:36 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/11/08 13:48:37 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "img_put_pixel.h"
#include <math.h>

static void	put_cells(t_cube *cube, t_vec2f player, int map_sz, float cell_sz);
static void	put_cell_pixel(t_cube *cube, t_point pixel_pos, t_point cell_pos);
static void	put_player(t_cube *cube, float player_padding, float cell_size);

void	render_minimap(t_cube *cube)
{
	int const	map_size = ft_min(SCREEN_WIDTH, SCREEN_HEIGHT) / 4;
	float const	cell_size = map_size / (float)MINIMAP_SIZE;
	float const	player_padding = MINIMAP_SIZE / 2.;
	t_vec2f		player;

	player.x = cube->player.pos.x - player_padding;
	player.y = cube->player.pos.y - player_padding;
	put_cells(cube, player, map_size, cell_size);
	put_player(cube, player_padding, cell_size);
}

static void	put_cells(t_cube *cube, t_vec2f player, int map_sz, float cell_sz)
{
	t_point	pixel;
	t_point	cell;

	pixel.y = -1;
	while (++pixel.y < map_sz)
	{
		pixel.x = -1;
		while (++pixel.x < map_sz)
		{
			cell.y = floor(player.y + (pixel.y / cell_sz));
			cell.x = floor(player.x + (pixel.x / cell_sz));
			put_cell_pixel(cube, pixel, cell);
		}
	}
}

static void	put_cell_pixel(t_cube *cube, t_point pixel_pos, t_point cell_pos)
{
	int	colour;

	colour = 0;
	if (cell_pos.y >= 0 && cell_pos.y < cube->map.height && \
			cell_pos.x >= 0 && cell_pos.x < cube->map.width && \
			cube->map.cells[cell_pos.y][cell_pos.x] == WALL)
		colour = 0xffffff;
	img_put_pixel(&cube->mlx.img, \
			MINIMAP_POS_Y + pixel_pos.y, \
			MINIMAP_POS_X + pixel_pos.x, \
			colour);
}

static void	put_player(t_cube *cube, float player_padding, float cell_size)
{
	t_point	a;
	t_point	b;

	a.x = MINIMAP_POS_X + player_padding * cell_size;
	a.y = MINIMAP_POS_Y + player_padding * cell_size;
	b.x = a.x + cube->player.dir.x * cell_size;
	b.y = a.y + cube->player.dir.y * cell_size;
	img_put_line(&cube->mlx.img, a, b, 0xff0f0f);
	a.x = MINIMAP_POS_X + (player_padding - 0.2) * cell_size;
	a.y = MINIMAP_POS_Y + (player_padding - 0.2) * cell_size;
	b.x = MINIMAP_POS_X + (player_padding + 0.2) * cell_size;
	b.y = MINIMAP_POS_Y + (player_padding + 0.2) * cell_size;
	img_put_rect(&cube->mlx.img, a, b, 0x00cc00);
}
