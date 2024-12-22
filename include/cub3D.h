/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:18:48 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 00:18:59 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

struct s_img
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	win_img;
};

struct s_cub
{
	struct s_mlx	mlx;
};

int		s_cub_init(struct s_cub *cub);
void	s_cub_destroy(struct s_cub *restrict cub);
int		s_mlx_init(struct s_mlx *mlx);
void	s_mlx_destroy(struct s_mlx *restrict mlx);
int		s_img_init(struct s_img *img, void *mlx_ptr, int width, int height);
void	s_img_destroy(struct s_img *restrict img);

#endif /* #ifndef CUB3D_H */
