/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:07:43 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:25:14 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <cub3D.h>
#include <libft/core.h>
#include <parsing.h>
#include <s_cub.h>
#include <s_img.h>
#include <s_map.h>
#include <s_mlx.h>

int	s_cub_init(struct s_cub *cub, const char *path)
{
	if (s_mlx_init(&cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D"))
		return (1);
	if (s_mlx_new_img(&cub->mlx, &cub->win_img, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		ft_putstr_fd("Error\nMlx failed to create window image\n", 2);
		return (1);
	}
	if (cub_parse_file(cub, path))
		return (1);
	return (0);
}

void	s_cub_destroy(struct s_cub *cub)
{
	int	i;

	i = 0;
	while (i < TX_NB)
		s_img_destroy(&cub->textures[i++]);
	s_img_destroy(&cub->win_img);
	s_mlx_destroy(&cub->mlx);
	s_map_destroy(&cub->map);
	ft_bzero(cub, sizeof(*cub));
}

void	s_cub_run(struct s_cub *cub)
{
	s_mlx_hook(&cub->mlx, DestroyNotify, &s_mlx_loop_end, &cub->mlx);
	s_mlx_key_hook(&cub->mlx, &key_hook, cub);
	s_mlx_loop_hook(&cub->mlx, &loop_hook, cub);
	s_mlx_loop(&cub->mlx);
}
