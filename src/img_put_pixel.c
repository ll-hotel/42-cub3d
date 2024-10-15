/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:14:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/21 05:43:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "img_put_pixel.h"

inline t_point	point(int x, int y)
{
	return ((t_point){x, y});
}

void	img_put_pixel(register t_img *img, register long y, register long x, \
		register int colour)
{
	const unsigned long	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (pixel_pos < (unsigned long)img->height * img->size_line)
		*(int *)(img->pixels + pixel_pos) = colour;
}

int	img_get_pixel(register t_img const *img, register long y, register long x)
{
	const unsigned long	pixel_pos = ((y * img->width) + x) * sizeof(int);

	if (pixel_pos < (unsigned long)img->height * img->size_line)
		return (*(int *)(img->pixels + pixel_pos));
	return (0);
}

void	img_put_rect(t_img *img, t_point top_left, t_point bottom_right, \
		int colour)
{
	int	y;
	int	x;

	y = top_left.y;
	while (y <= bottom_right.y)
	{
		x = top_left.x;
		while (x <= bottom_right.x)
		{
			img_put_pixel(img, y, x, colour);
			x += 1;
		}
		y += 1;
	}
}
