/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:05:11 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/04 16:42:55 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include "img_put_pixel.h"
# include "vec2f.h"
# define WALL '1'
# define FLOOR '0'
# define EMPTY ' '
# define RAY_WIDTH 2
# define SCREEN_WIDTH (1080 * 2)
# define SCREEN_HEIGHT (720 * 2)
# define FOV 0.66f
# define CAMERA_PLANE_WIDTH ((float)SCREEN_WIDTH / (float)RAY_WIDTH)
# define NAME "Cub3D"
# define PI 3.141592

enum e_hitside
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;
typedef struct s_cube	t_cube;
typedef struct s_img	t_img;
typedef struct s_ray	t_ray;
typedef enum e_hitside	t_hitside;

struct	s_player
{
	t_vec2f	pos;
	t_vec2f	dir;
	float	axis;
	// float	dir_z; //if we use mouse pointer to change POV
	t_vec2f	camera;
	char	turning;
	char	walking;
};

struct s_ray
{
	t_vec2f		deltadist;
	t_vec2f		step;
	t_vec2f		dir;
	t_vec2f		side_dist;
	float		perpwalldist;
	t_hitside	side;
	int			drawstart;
	int			drawend;
};

struct	s_map
{
	char	**cells;
	int		width;
	int		height;
};

struct	s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
};

struct	s_cube
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	t_img		no_texture;
	t_img		so_texture;
	t_img		we_texture;
	t_img		ea_texture;
	u_int		f_colour;
	u_int		c_colour;
};

int		init_cube(t_cube *cube, const char *file_name);
void	destroy_cube(t_cube *cube);

int		cube_parse_file(t_cube *cube, const char *file_name);
int		read_file(const int fd, char ***lines);
char	*find_line(char **lines, const char *prefix);
int		parsing_textures(t_cube *cube, char **lines);
int		parsing_colours(t_cube *cube, char **lines);
int		parsing_map(t_cube *cube, char **lines);
int		grid_values_check(char **grid);
int		grid_stretch_lines(char **grid);
int		grid_wall_check(char **grid);

void	cube_render(t_cube *cube);
void	ray_init_dda(t_ray *ray, t_player *player, int x);
void	ray_perform_dda(t_ray *ray, t_cube *cube);
void	ray_find_drawing_limits(t_ray *ray);
void	cube_render(t_cube *cube);
void	render_minimap(t_cube *cube);

void	cube_put_image(t_cube *cube);
int		cube_error(char *__message);
int		ft_str_endswith(const char *s1, const char *s2);

void	cube_loop(t_cube *cube);
#endif
