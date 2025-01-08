/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:35:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 14:49:47 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "parsing.h"
#include "s_mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_texture_filename(t_line const *line);
static int	store_texture(t_img *textures, const t_mlx *mlx, const char *key, \
		char *filename);

int	parsing_textures(t_img *textures, const t_mlx *mlx, t_line *lines)
{
	const char *const	keys[] = {"NO", "SO", "EA", "WE", NULL};
	const char			*key;
	t_line				*line;
	char				*filename;
	int					key_i;

	key_i = -1;
	while (keys[++key_i])
	{
		key = keys[key_i];
		line = find_line_by_key(lines, key);
		if (line == NULL)
			return (ft_dprintf(2, "Error\nMissing key '%s'\n", key), 1);
		else if (find_line_by_key(line + 1, key) != NULL)
			return (ft_dprintf(2, "Error\nDuplicate key '%s'\n", key), 1);
		filename = get_texture_filename(line);
		if (!filename)
			return (1);
		ft_strtrim_inplace(filename, " ");
		if (store_texture(textures, mlx, key, filename))
			return (1);
	}
	return (0);
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
		ft_dprintf(2, "Error\n%s is not a xpm file\n", line->value);
	return (NULL);
}

static int	store_texture(t_img *textures, const t_mlx *mlx, const char *key, \
		char *filename)
{
	t_img	*texture;

	if (ft_strcmp(key, "NO") == 0)
		texture = &textures[TX_NORTH];
	else if (ft_strcmp(key, "SO") == 0)
		texture = &textures[TX_SOUTH];
	else if (ft_strcmp(key, "EA") == 0)
		texture = &textures[TX_EAST];
	else if (ft_strcmp(key, "WE") == 0)
		texture = &textures[TX_WEST];
	else
		return (1);
	if (s_mlx_xpm_file_to_img(mlx, texture, filename))
	{
		ft_putstr_fd("Error\nMlx failed to parse xpm file\n", 2);
		return (1);
	}
	return (0);
}
