/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:09:24 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:09:25 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MLX_H
# define S_MLX_H
# include "./s_img.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	win_img;
}	t_mlx;

int		s_mlx_init(t_mlx *mlx);
void	s_mlx_destroy(t_mlx *mlx);

#endif /* ifndef S_MLX_H */
