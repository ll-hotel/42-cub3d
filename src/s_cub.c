/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:08:11 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 01:44:30 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "mlx.h"

int	t_cub_init(t_cub *cub)
{
	if (t_mlx_init(&cub->mlx))
		return (1);
	return (0);
}

void	t_cub_destroy(t_cub *cub)
{
	t_mlx_destroy(&cub->mlx);
	ft_bzero(cub, sizeof(*cub));
}

void	t_cub_run(t_cub *cub)
{
	mlx_hook(cub->mlx.win_ptr, 17, 0, &mlx_loop_end, cub->mlx.mlx_ptr);
	mlx_key_hook(cub->mlx.win_ptr, (void *)&key_hook, cub);
	mlx_loop_hook(cub->mlx.mlx_ptr, (void *)&loop_hook, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}
