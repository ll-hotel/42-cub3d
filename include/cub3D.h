/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:53:50 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/29 18:56:39 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define WALL '1'
# define FLOOR '0'
# define EMPTY ' '
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define NAME "Cub3D"

enum e_hitside
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_player	  t_player;
typedef struct s_map	  t_map;
typedef struct s_mlx	  t_mlx;
typedef struct s_cube	  t_cube;
typedef struct s_img	  t_img;
typedef struct s_raycast  t_raycast;
typedef enum e_hitside	  t_hitside;

struct	s_player
{
	float	x;
	float	y;
	float	dirX;
	float	dirY;
	float	dirZ; //if we use mouse pointer to change POV
	float	cameraX;
	float	cameraY;
};

struct s_raycast
{
	float	  deltadistX;
	float	  deltadistY;
	int		  stepX;
	int		  stepY;

	float	  raydirX;
	float	  raydirY;
	float	  sidedistX;
	float	  sidedistY;
	float	  perpwalldist;
	t_hitside side;
	int		  drawstart;
	int		  drawend;
};

struct	s_map
{
	char	**cells;
	int		width;
	int		heigth;
};

struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixels;
	int		bpp;
	int		size_line;
	int		endian;
};

struct	s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
};

struct    s_cube
{
  t_map       map;
  t_player    player;
  t_mlx		    mlx;
	t_img		    no_texture;
	t_img		    so_texture;
	t_img		    we_texture;
	t_img		    ea_texture;
	u_int		    f_colour;
	u_int		    c_colour;
};

int   init_mlx(t_cube cub);

int		cube_parse_file(t_cube *cube, const char *file_name);
int		read_file(const int fd, char ***lines);
char	*find_line(char **lines, const char *prefix);
int		parsing_textures(t_cube *cube, char **lines);
int		parsing_colours(t_cube *cube, char **lines);
int		parsing_map(t_cube *cube, char **lines);
int		grid_values_check(char **grid);
int		grid_stretch_lines(char **grid);
int		grid_wall_check(char **grid);

int		cube_error(char *__message);
int		ft_str_endswith(const char *s1, const char *s2);

#endif
