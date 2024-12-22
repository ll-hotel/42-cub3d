/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:08:11 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 00:42:59 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/core.h"

int	s_cub_init(struct s_cub *cub)
{
	if (s_mlx_init(&cub->mlx))
		return (1);
	return (0);
}

void	s_cub_destroy(struct s_cub *cub)
{
	s_mlx_destroy(&cub->mlx);
	ft_bzero(cub, sizeof(*cub));
}
