/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:03:11 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/08 20:39:16 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_PUT_PIXEL_H
# define IMG_PUT_PIXEL_H

typedef struct s_img	t_img;
typedef struct s_point	t_point;

struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixels;
	int		bpp;
	int		size_line;
	int		endian;
};

struct	s_point
{
	int	x;
	int	y;
};

t_point	point(int x, int y);
void	img_put_pixel(t_img *img, long y, long x, int colour);
int		img_get_pixel(t_img *img, long y, long x);
void	img_put_rect(t_img *img, t_point const top_left, \
		t_point const bottom_right, int const colour);
void	img_put_line(t_img *img, t_point p1, t_point p2, const int colour);
#endif
