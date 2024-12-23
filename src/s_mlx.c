/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:08:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 01:44:49 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "mlx.h"
#include <stdlib.h>

int	t_mlx_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Cub3D");
	if (!mlx->win_ptr)
		return (1);
	if (t_img_init(&mlx->win_img, mlx->mlx_ptr, 1920, 1080))
		return (1);
	return (0);
}

void	t_mlx_destroy(t_mlx *mlx)
{
	if (mlx->win_img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->win_img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	ft_bzero(mlx, sizeof(*mlx));
}
