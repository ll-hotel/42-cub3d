/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:35:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/15 12:50:48 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
#include "ft_basics.h"
#include "ft_dprintf.h"
#include "mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	check_founds(char *no, char *so, char *we, char *ea);
static int	check_line_format(char *const line, const char *direction);
static int	check_filename_format(char *const filename);
static int	store_texture(void *mlx_ptr, t_img *texture, char *const filename);

int	parsing_textures(t_cube *cube, char **lines)
{
	char *const	no = find_line(lines, "NO ");
	char *const	so = find_line(lines, "SO ");
	char *const	we = find_line(lines, "WE ");
	char *const	ea = find_line(lines, "EA ");

	if (!check_founds(no, so, we, ea))
		return (0);
	if (!check_line_format(no, "NO ") || \
			!check_line_format(so, "SO ") || \
			!check_line_format(we, "WE ") || \
			!check_line_format(ea, "EA "))
		return (0);
	if (!store_texture(cube->mlx.ptr, &cube->no_texture, no + 3) || \
			!store_texture(cube->mlx.ptr, &cube->so_texture, so + 3) || \
			!store_texture(cube->mlx.ptr, &cube->we_texture, we + 3) || \
			!store_texture(cube->mlx.ptr, &cube->ea_texture, ea + 3))
		return (0);
	return (1);
}

static int	check_founds(char *no, char *so, char *we, char *ea)
{
	if (!no)
		return (cube_error("Could not find NOrth texture\n"));
	if (!so)
		return (cube_error("Could not find SOuth texture\n"));
	if (!we)
		return (cube_error("Could not find WEst texture\n"));
	if (!ea)
		return (cube_error("Could not find EAst texture\n"));
	return (1);
}

static int	check_line_format(char *const line, const char *direction)
{
	if (ft_strncmp(line, direction, 3))
	{
		ft_dprintf(2, "Error\nBad line format `%s'\n", line);
		return (0);
	}
	if (!line[3])
		return (cube_error("missing texture filename"));
	return (check_filename_format(line + 3));
}

static int	check_filename_format(char *const filename)
{
	if (!ft_str_endswith(filename, ".xpm"))
	{
		ft_dprintf(2, "Error\n%s: wrong file extension " \
				"(should be a .xpm file)\n", filename);
		return (0);
	}
	return (1);
}

static int	store_texture(void *mlx_ptr, t_img *texture, char *const filename)
{
	const int	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		ft_dprintf(2, "Error\nCould not open %s: %s\n", \
				filename, strerror(errno));
		return (0);
	}
	close(fd);
	texture->ptr = mlx_xpm_file_to_image(mlx_ptr, filename, \
			&texture->width, &texture->height);
	if (texture->ptr)
		texture->pixels = mlx_get_data_addr(texture->ptr, &texture->bpp, \
				&texture->size_line, &texture->endian);
	if (!texture->ptr || !texture->pixels)
	{
		cube_error("Minilibx issue\n");
		return (0);
	}
	return (1);
}
