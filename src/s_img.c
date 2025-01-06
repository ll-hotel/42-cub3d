/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:08:09 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/05 22:46:29 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_img.h"
#include "libft/core.h"
#include "mlx.h"
#include <stddef.h>

int	s_img_init(t_img *img, void *mlx_ptr, int width, int height)
{
	img->mlx_ptr = mlx_ptr;
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!img->img_ptr)
	{
		ft_putstr_fd("Error\nMlx image init failed\n", 2);
		return (1);
	}
	img->data_addr = mlx_get_data_addr(img->img_ptr, \
			&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!img->data_addr)
	{
		ft_putstr_fd("Error\nMlx image get_data_addr failed\n", 2);
		return (1);
	}
	return (0);
}

void	s_img_destroy(t_img *img)
{
	if (img->img_ptr)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	ft_bzero(img, sizeof(*img));
}

__attribute__((__always_inline__))
void	s_img_put_pixel(t_img *img, int x, int y, int pixel)
{
	size_t	addr;

	addr = (size_t)img->data_addr;
	addr += y * img->size_line;
	addr += x * 4;
	*(int *)addr = pixel;
}

__attribute__((__always_inline__))
int	s_img_get_pixel(const t_img *img, int x, int y)
{
	size_t	addr;

	addr = (size_t)img->data_addr;
	addr += y * img->size_line;
	addr += x * 4;
	return (*(int *)addr);
}

void	s_img_put_t_img(t_img *dst, const t_img *src, int x, int y)
{
	int	ix;
	int	iy;
	int	pixel;

	iy = -1;
	while (++iy < src->height)
	{
		ix = -1;
		while (++ix < src->width)
		{
			pixel = s_img_get_pixel(src, ix, iy);
			s_img_put_pixel(dst, x + ix, y + iy, pixel);
		}
	}
}
