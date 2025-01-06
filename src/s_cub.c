/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:07:43 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/05 22:49:47 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"
#include "mlx.h"
#include "parsing.h"
#include <X11/X.h>

int	s_cub_init(struct s_cub *cub, const char *path)
{
	if (s_mlx_init(&cub->mlx))
		return (1);
	if (cub_parse_file(cub, path))
		return (1);
	return (0);
}

void	s_cub_destroy(struct s_cub *cub)
{
	s_mlx_destroy(&cub->mlx);
	ft_bzero(cub, sizeof(*cub));
}

void	s_cub_run(struct s_cub *cub)
{
	mlx_hook(cub->mlx.win_ptr, DestroyNotify, 0, &mlx_loop_end, cub->mlx.mlx_ptr);
	mlx_key_hook(cub->mlx.win_ptr, (void *)&key_hook, cub);
	mlx_loop_hook(cub->mlx.mlx_ptr, (void *)&loop_hook, cub);
	ft_putstr_fd("Looping!\n", 1);
	mlx_loop(cub->mlx.mlx_ptr);
}
