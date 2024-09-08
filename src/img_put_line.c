/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:33:50 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/08 20:33:52 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "img_put_pixel.h"
#include <math.h>

void	img_put_line(t_img *img, t_point p1, t_point p2, const int colour)
{
	const t_vec2f	d = (t_vec2f){p2.x - p1.x, p2.y - p1.y};
	t_vec2f			slope;
	int				steps;
	float			x;
	float			y;

	x = p1.x;
	y = p1.y;
	steps = roundf(ft_maxf(ft_absf(d.x), ft_absf(d.y)));
	slope = (t_vec2f){d.x / steps, d.y / steps};
	img_put_pixel(img, y, x, colour);
	while (steps-- > 0)
	{
		x += slope.x;
		y += slope.y;
		img_put_pixel(img, roundf(y), roundf(x), colour);
	}
}
