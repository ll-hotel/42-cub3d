/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:12 by omougel           #+#    #+#             */
/*   Updated: 2024/07/31 00:59:09 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_pixel_put(int x, int y, t_img *img, u_int32_t color)
{
	int	offset;

	offset = y * img->size_line + x * (img->bpp / 8);
	*(unsigned int *)(img->pixels + offset) = color;
}

void  init_sidedist_and_find_step(t_raycast *raycast, t_player player)
{
	if (raycast->raydirX > 0)
	{
		raycast->stepX = -1;
		raycast->sidedistX = (player.x - (int)player.x) * raycast->deltadistX;
	}
	else
	{
		raycast->stepX = 1;
		raycast->sidedistX = ((int)player.x + 1 - player.x) *
			raycast->deltadistX;
	}
	if (raycast->raydirY > 0)
	{
		raycast->stepY = -1;
		raycast->sidedistY = (player.y - (int)player.y) * raycast->deltadistY;
	}
	else
	{
		raycast->stepY = 1;
		raycast->sidedistY = ((int)player.y + 1	- player.y) *
			raycast->deltadistY;
	}
}

void  find_delta_and_init_sidedist(t_raycast *raycast, int x, t_player player)
{
	float	  planeX;

	planeX = 2 * x / (float)SCREEN_WIDTH - 1;
	raycast->raydirX = player.dirX + player.cameraX * planeX;
	raycast->raydirY = player.dirY + player.cameraY * planeX;
	raycast->deltadistX = sqrt(1 + (raycast->raydirY * raycast->raydirY) /
							(raycast->raydirX * raycast->raydirX));
	raycast->deltadistY = sqrt(1 + (raycast->raydirX * raycast->raydirX) /
							(raycast->raydirY * raycast->raydirY));
	init_sidedist_and_find_step(raycast, player);
}

t_raycast init_data_dda(t_player player, int x)
{
	t_raycast raycast;

	find_delta_and_init_sidedist(&raycast, x, player);
	return (raycast);
}

void  perform_dda(t_raycast *raycast, t_cube cub)
{
	int	hit;
	int	mapX;
	int	mapY;

	hit = 0;
	mapX = (int)cub.player.x;
	mapY = (int)cub.player.y;
	while (hit == 0)
	{
		if (raycast->sidedistX < raycast->sidedistY)
		{
			raycast->sidedistX += raycast->deltadistX;
			mapX += raycast->stepX;
			if (raycast->stepX > 0)
				raycast->side = EAST;
			else
				raycast->side = WEST;
		}
		else
		{
			raycast->sidedistY += raycast->deltadistY;
			mapY += raycast->stepY;
			if (raycast->stepY > 0)
				raycast->side = NORTH;
			else
				raycast->side = SOUTH;
		}
		if (cub.map.cells[mapY][mapX] == '1')
			hit = 1;
	}
}

void  find_draw_start_and_end(t_raycast *raycast)
{
	int	lineheight;

	if (raycast->side == EAST || raycast->side == WEST)
		raycast->perpwalldist = raycast->sidedistX - raycast->deltadistX;
	else
		raycast->perpwalldist = raycast->sidedistY - raycast->deltadistY;
	lineheight = (int)(SCREEN_HEIGHT / raycast->perpwalldist);
	raycast->drawstart = (int)(-lineheight / 2) + (int)(SCREEN_HEIGHT / 2);// - player.dirZ;
	if (raycast->drawstart < 0)
		raycast->drawstart = 0;
	raycast->drawend = (int)(lineheight / 2) + (int)(SCREEN_HEIGHT / 2);// - player.dirZ;
	if (raycast->drawend >= SCREEN_HEIGHT)
		raycast->drawend = SCREEN_HEIGHT - 1;
}

t_raycast  DDA_alg(t_cube cub, int x)
{
	t_raycast raycast;

	raycast = init_data_dda(cub.player, x);
	perform_dda(&raycast, cub);
	find_draw_start_and_end(&raycast);
	return (raycast);
}

t_img find_texture(t_cube cub, t_hitside side)
{
	if (side ==	NORTH)
		return (cub.no_texture);
	if (side == SOUTH)
		return (cub.so_texture);
	if (side == EAST)
		return (cub.ea_texture);
	if (side == WEST)
		return (cub.we_texture);
	return (cub.mlx.img);
}

int  init_texX(t_raycast raycast, t_cube cub, t_img texture)
{
	float wallX;
	int	texX;

	if (raycast.side == WEST || raycast.side == EAST)
		wallX = cub.player.y + raycast.perpwalldist * raycast.raydirY;
	else
		wallX = cub.player.x + raycast.perpwalldist * raycast.raydirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * texture.width);// ca commence a devenir obscure bien relire les explications pour cette partie la
	if (raycast.side == EAST || raycast.side == SOUTH)
		texX = texture.width - texX - 1;
	return (texX);
}

void  handle_texture(t_raycast raycast, t_cube cub, t_img tex, int x)
{
	float step;
	float texpos;
	int	  texX;
	int	  texY;
	int	  y;

	texX = init_texX(raycast, cub, tex);
	step = 1.0 * tex.height / (int)(SCREEN_HEIGHT / raycast.perpwalldist);
	texpos = (raycast.drawstart - SCREEN_HEIGHT / 2 + (int)(SCREEN_HEIGHT / raycast.perpwalldist) / 2) * step;
	y = raycast.drawstart;
	while (y < raycast.drawend)
	{
		texY = (int)texpos & (tex.height - 1);
		texpos += step;
		my_pixel_put(x, y, &cub.mlx.img, tex.pixels[tex.size_line * texY + texX * (tex.bpp / 8)]);
		y++;
	}
}

void  handle_pixel(t_raycast raycast, t_cube cub, int x)
{
	int	y;

	y = -1;
	while (++y < raycast.drawstart)
		my_pixel_put(x, y, &cub.mlx.img, cub.c_colour);
	handle_texture(raycast, cub, find_texture(cub, raycast.side), x);
	y = raycast.drawend;
	while (++y < SCREEN_HEIGHT)
		my_pixel_put(x, y, &cub.mlx.img, cub.f_colour);
}

void	cub_render(t_cube cub)
{
	int		  x;
	t_raycast raycast;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		raycast = DDA_alg(cub, x);
		handle_pixel(raycast, cub, x);
	}
	mlx_put_image_to_window(cub.mlx.ptr, cub.mlx.win, cub.mlx.img.ptr, 0, 0);
}
