/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:07:52 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/05 22:45:53 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <s_mlx.h>
#include "libft/core.h"
#include "mlx.h"
#include <stdlib.h>

int	s_mlx_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		ft_putstr_fd("Error\nMlx init failed\n", 2);
		return (1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Cub3D");
	if (!mlx->win_ptr)
	{
		ft_putstr_fd("Error\nMlx window init failed\n", 2);
		return (1);
	}
	if (s_img_init(&mlx->win_img, mlx->mlx_ptr, 1920, 1080))
		return (1);
	return (0);
}

void	s_mlx_destroy(t_mlx *mlx)
{
	if (mlx->win_img.img_ptr)
		s_img_destroy(&mlx->win_img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	ft_bzero(mlx, sizeof(*mlx));
}
