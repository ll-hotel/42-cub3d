/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:07:52 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:23:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <s_mlx.h>
#include "cub3D.h"
#include "libft/core.h"
#include "mlx.h"
#include <stdlib.h>

int	s_mlx_init(t_mlx *mlx, int width, int height, char *title)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		ft_putstr_fd("Error\nMlx init failed\n", 2);
		return (1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, title);
	if (!mlx->win_ptr)
	{
		ft_putstr_fd("Error\nMlx window init failed\n", 2);
		return (1);
	}
	return (0);
}

void	s_mlx_destroy(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	ft_bzero(mlx, sizeof(*mlx));
}
