/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:45:51 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/04 16:19:27 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "img_put_pixel.h"
#include "vec2f.h"

static void	setup(t_cube *cube, t_point *offset, int *cell_size);
static void	put_cell(t_cube *cube, t_point cell, t_point offset, int size);
static int	cell_colour(t_cube *cube, int y, int x);
static void put_player(t_cube *cube, t_point offset, int size);

void	render_minimap(t_cube *cube)
{
	int const	minimap_size = 15;
	t_point		offset;
	int			cell_size;
	t_point		cell;

	cell_size = minimap_size / 2;
	setup(cube, &offset, &cell_size);
	cell.y = 0;
	while (cell.y < minimap_size)
	{
		cell.x = -1;
		while (++cell.x < minimap_size)
			put_cell(cube, cell, offset, cell_size);
		cell.y += 1;
	}
	img_put_line(&cube->mlx.img, point(minimap_size * cell_size, 0), \
		point(minimap_size * cell_size, minimap_size * cell_size), 0xffffff);
	img_put_line(&cube->mlx.img, point(0, minimap_size * cell_size), \
		point(minimap_size * cell_size, minimap_size * cell_size), 0xffffff);
	put_player(cube, offset, cell_size);
}

static void	setup(t_cube *cube, t_point *offset, int *cell_size)
{
	float const		max_map_size = ft_min(SCREEN_HEIGHT, SCREEN_WIDTH) / 4.;
	t_point const	p = point(cube->player.pos.x, cube->player.pos.y);
	int const		cell_padding = *cell_size;

	*offset = point( \
				 ft_max(p.x - cell_padding, 0), \
				 ft_max(p.y - cell_padding, 0) \
				 );
	*cell_size = max_map_size / (cell_padding * 2 + 1);
}

static void	put_cell(t_cube *cube, t_point cell, t_point offset, int size)
{
	t_point const	top_left = {cell.x * size, cell.y * size};
	t_point const	bottom_right = {top_left.x + size, top_left.y + size};
	int const		colour = cell_colour(cube, cell.y + offset.y, \
			cell.x + offset.x);

	img_put_rect(&cube->mlx.img, top_left, bottom_right, colour);
}

static int	cell_colour(t_cube *cube, int y, int x)
{
	if (y >= cube->map.height || x >= cube->map.width)
		return (0);
	return ((cube->map.cells[y][x] == WALL) * 0xffffff);
}

static void put_player(t_cube *cube, t_point offset, int size)
{
	const float px = (cube->player.pos.x - offset.x) * size;
	const float py = (cube->player.pos.y - offset.y) * size;
	t_point		p;
	t_point		p2;

	img_put_rect(&cube->mlx.img,  \
			  point(px - size / 4., py - size / 4.), \
			  point(px + size / 4., py + size / 4.), \
			  0x00ff00);
	p = point(px + cube->player.dir.x * size, py + cube->player.dir.y * size);
	img_put_line(&cube->mlx.img, \
			  point(px, py), \
			  p, \
			  0xff0000);
	p.x = p.x - (cube->player.camera.x * size / 2);
	p.y = p.y - (cube->player.camera.y * size / 2);
	p2 = point(p.x + cube->player.camera.x * size, \
			p.y + cube->player.camera.y * size);
	img_put_line(&cube->mlx.img, p, p2, 0xf0f0f0);
}
