/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:35:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 17:25:05 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include "ft_dprintf.h"
#include "mlx.h"
#include "parsing.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_texture_filename(t_line const *line);
static int	store_texture(t_cube *cube, char const *key, char *filename);

int	parsing_textures(t_cube *cube, t_line *lines)
{
	char const *const	keys[] = {"NO", "SO", "EA", "WE", NULL};
	char const			*key;
	t_line				*line;
	char				*filename;
	int					key_i;

	key_i = -1;
	while (keys[++key_i])
	{
		key = keys[key_i];
		line = find_line_by_key(lines, key);
		if (line == NULL)
			return (ft_dprintf(2, "Error\nMissing key '%s'\n", key), 0);
		else if (find_line_by_key(line + 1, key) != NULL)
			return (ft_dprintf(2, "Error\nDuplicate key '%s'\n", key), 0);
		filename = get_texture_filename(line);
		if (!filename)
			return (0);
		ft_strtrim_inplace(filename);
		if (!store_texture(cube, key, filename))
			return (0);
	}
	return (1);
}

static char	*get_texture_filename(t_line const *line)
{
	if (line->value == NULL)
		ft_dprintf(2, "Error\nMissing value for key '%s'\n", line->key);
	else if (ft_strchr(line->value, ' ') != NULL)
		ft_dprintf(2, "Error\nBad value '%s' for key '%s'\n", line->value, \
				line->key);
	else if (ft_str_endswith(line->value, ".xpm") == 1)
		return (line->value);
	else
		ft_dprintf(2, "Error\nFile %s is not a xpm file\n", line->value);
	return (NULL);
}

static int	store_texture(t_cube *cube, char const *key, char *filename)
{
	t_img	*texture;

	if (ft_strcmp(key, "NO") == 0)
		texture = &cube->no_texture;
	else if (ft_strcmp(key, "SO") == 0)
		texture = &cube->so_texture;
	else if (ft_strcmp(key, "EA") == 0)
		texture = &cube->ea_texture;
	else if (ft_strcmp(key, "WE") == 0)
		texture = &cube->we_texture;
	else
		return (0);
	texture->ptr = mlx_xpm_file_to_image(cube->mlx.ptr, filename, \
			&texture->width, &texture->height);
	if (texture->ptr == NULL)
	{
		ft_dprintf(2, "Error\nMlx failed to parse file '%s'\n", filename);
		return (0);
	}
	texture->pixels = mlx_get_data_addr(texture->ptr, &texture->bpp, \
			&texture->size_line, &texture->endian);
	return (1);
}
