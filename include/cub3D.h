/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:18:48 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 01:43:22 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_img
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	win_img;
}	t_mlx;

typedef struct s_cub
{
	t_mlx	mlx;
}	t_cub;

int		t_cub_init(t_cub *cub);
void	t_cub_destroy(t_cub *restrict cub);
void	t_cub_run(t_cub *cub);

int		t_mlx_init(t_mlx *mlx);
void	t_mlx_destroy(t_mlx *restrict mlx);

int		t_img_init(t_img *img, void *mlx_ptr, int width, int height);
void	t_img_destroy(t_img *restrict img);
void	t_img_put_pixel(t_img *img, int x, int y, int pixel);
int		t_img_get_pixel(const t_img *img, int x, int y);
void	t_img_put_t_img(t_img *dst, const t_img *src, int x, int y);

void	loop_hook(t_cub *cub);
void	key_hook(int keysym, t_cub *cub);

#endif /* #ifndef CUB3D_H */
