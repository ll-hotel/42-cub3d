/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_xpm_file_to_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:59:03 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:25 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <s_mlx.h>

int	s_mlx_xpm_file_to_img(const t_mlx *mlx, t_img *img, char *filename)
{
	*img = (t_img){0};
	img->mlx_ptr = mlx->mlx_ptr;
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
			filename, &img->width, &img->height);
	if (!img->img_ptr)
		return (1);
	img->pixels = img->width * img->height;
	img->data_addr = mlx_get_data_addr(img->img_ptr, \
			&img->bits_per_pixel, &img->size_line, &img->endian);
	return (0);
}
