/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:14:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/11 19:30:33 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include "img_put_pixel.h"

void	img_put_pixel(t_img *img, const int y, const int x, const int colour)
{
	const int	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (0 <= pixel_pos && pixel_pos < img->height * img->size_line)
		*(int *)(img->pixels + pixel_pos) = colour;
}

int	img_get_pixel(t_img *const img, const int y, const int x)
{
	const int	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (pixel_pos < img->height * img->size_line)
		return (*(int *)(img->pixels + pixel_pos));
	return (0);
}

void	img_put_rect(t_img *img, const t_point top_left, \
		const t_point bottom_right, const int colour)
{
	int	y;
	int	x;

	y = top_left.y;
	while (y < bottom_right.y)
	{
		x = top_left.x;
		while (x < bottom_right.x)
		{
			img_put_pixel(img, y, x, colour);
			x += 1;
		}
		y += 1;
	}
}
