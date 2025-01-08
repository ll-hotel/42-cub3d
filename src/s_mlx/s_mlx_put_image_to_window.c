/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_put_image_to_window.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:19:59 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:20:34 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "s_mlx.h"

void	s_mlx_put_image_to_window(const t_mlx *mlx, \
		const t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, x, y);
}
