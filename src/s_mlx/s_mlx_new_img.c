/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_new_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:13:04 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:13:46 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <s_img.h>
#include <s_mlx.h>

int	s_mlx_new_img(const t_mlx *mlx, t_img *img, int width, int height)
{
	return (s_img_init(img, mlx->mlx_ptr, width, height));
}
