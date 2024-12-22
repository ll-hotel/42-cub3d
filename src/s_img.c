/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:09:21 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 00:43:16 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "mlx.h"

int	s_img_init(struct s_img *img, void *mlx_ptr, int width, int height)
{
	img->mlx_ptr = mlx_ptr;
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!img->img_ptr)
		return (1);
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	if (!img->data_addr)
		return (1);
	return 0;
}

void	s_img_destroy(struct s_img *img)
{
	if (img->img_ptr)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	ft_bzero(img, sizeof(*img));
}
