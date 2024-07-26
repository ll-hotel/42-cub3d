/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:53:50 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/25 15:53:51 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# define OEL -42
# define EMPTY -1
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_player	t_player;
typedef struct s_map	 t_map;
typedef struct s_mlx	 t_mlx;

struct	s_player
{
	float	x;
	float	y;
	float	h_angle;
	float	v_angle;
};

struct	s_map
{
	char	**cells;
	int		width;
	int		heigth;
};

struct	s_mlx
{
	void	*mlx_ptr;
	u_char	*pixels;
	int		bpp;
	int		len;
	// ...
};

struct	s_cube
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	// ...
};

#endif
