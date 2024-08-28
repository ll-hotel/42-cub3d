/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:03:11 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/21 00:00:24 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_MLX_H
# define PUT_MLX_H
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
void	img_put_pixel(t_img *img, long const y, long const x, int const colour);
int		img_get_pixel(t_img *const img, long const y, long const x);
void	img_put_rect(t_img *img, t_point const top_left, \
		t_point const bottom_right, int const colour);
void	img_put_line(t_img *img, t_point p1, t_point p2, const int colour);
#endif
