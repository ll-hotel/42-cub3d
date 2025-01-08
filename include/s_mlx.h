/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:09:24 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:22:29 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MLX_H
# define S_MLX_H
# include "s_img.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

int		s_mlx_init(t_mlx *mlx, int width, int height, char *title);
void	s_mlx_destroy(t_mlx *mlx);

void	s_mlx_hook(const t_mlx *mlx, int x_event, void (*funct)(), void *param);
void	s_mlx_key_hook(const t_mlx *mlx, void (*funct)(), void *param);
void	s_mlx_loop_hook(const t_mlx *mlx, void (*funct)(), void *param);
void	s_mlx_loop(const t_mlx *mlx);
void	s_mlx_loop_end(const t_mlx *mlx);

int		s_mlx_new_img(const t_mlx *mlx, t_img *img, int width, int height);
int		s_mlx_xpm_file_to_img(const t_mlx *mlx, t_img *img, char *filename);

void	s_mlx_put_image_to_window(const t_mlx *mlx, \
		const t_img *img, int x, int y);

#endif /* ifndef S_MLX_H */
