/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:34:23 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/11 20:02:19 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_put_pixel.h"
#include "libft.h"

static void	put_straight(t_img *img, \
		const t_point start, const t_point end, const int colour);
static void	put_l(t_img *img, \
		const t_point start, const t_point end, const int colour);

void	img_put_line(t_img *img, t_point start, t_point end, const int colour)
{
	int	tmp;

	if (start.x == end.x || start.y == end.y)
		return (put_straight(img, start, end, colour));
	if (start.x > end.x)
	{
		tmp = end.x;
		end.x = start.x;
		start.x = tmp;
	}
	if (start.y > end.y)
	{
		tmp = end.y;
		end.y = start.y;
		start.y = tmp;
	}
	put_l(img, start, end, colour);
}

static void	put_l(t_img *img, \
		const t_point start, const t_point end, const int colour)
{
	t_point const	error_step = {(end.x - start.x) * 2, (end.y - start.y) * 2};
	int	const		max_step = ft_max(end.x - start.x, end.y - start.y);
	t_point			pixel;
	t_point			error;
	int				step;

	pixel = start;
	step = 0;
	while (step < max_step)
	{
		img_put_pixel(img, pixel.y, pixel.x, colour);
		error.x += error_step.x;
		error.y += error_step.y;
		pixel.x += error.x >= 0;
		pixel.y += error.y >= 0;
		if (error.x >= 0)
			error.x -= (end.y - pixel.y) * 2;
		if (error.y >= 0)
			error.y -= (end.x - pixel.x) * 2;
		step += 1;
	}
}

static void	put_straight(t_img *img, \
		const t_point start, const t_point end, const int colour)
{
	if (start.x < end.x)
		img_put_rect(img, start, (t_point){end.x, end.y + 1}, colour);
	else if (start.x > end.x)
		img_put_rect(img, end, (t_point){start.x, start.y + 1}, colour);
	else if (start.y < end.y)
		img_put_rect(img, start, (t_point){end.x + 1, end.y}, colour);
	else
		img_put_rect(img, end, (t_point){start.x + 1, start.y}, colour);
}
