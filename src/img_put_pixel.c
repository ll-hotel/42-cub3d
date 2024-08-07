/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:14:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/06 01:46:40 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"

#include <stdio.h>
void	img_put_pixel(t_img *img, int y, int x, int colour)
{
	const int	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (pixel_pos < img->height * img->size_line)
		*(int *)(img->pixels + pixel_pos) = colour;
}

int	img_get_pixel(t_img *img, int y, int x)
{
	const int	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (pixel_pos < img->height * img->size_line)
		return (*(int *)(img->pixels + pixel_pos));
	return (0);
}

void	cube_put_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx.ptr, \
						cube->mlx.win, \
						cube->mlx.img.ptr, \
						0, 0);
}
