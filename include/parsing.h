/* ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:18:58 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 12:27:30 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/

#ifndef PARSING_H
# define PARSING_H
#include "s_cub.h"
# include "s_map.h"
# include <sys/types.h>

/* 
 *A type storing the line raw `char *` pointer, with its key/value pair.
 *If the line is empty or only made of spaces, both `key` and `value` shall be
 *NULL.
 *If the line contains only one word, only `key` shall be set.
 *Else, both `key` and `value` shall be set accordingly.
 *Please note that `value` can contain multiple words separated with one or
 *more spaces.
 */
typedef struct s_line	t_line;

struct	s_line
{
	char	*ptr;
	char	*key;
	char	*value;
};

int		read_file(char const *file_name, t_line **lines);

int		parsing_textures(t_img *textures, t_line *lines);
int		parsing_colours(t_uint *colors, t_line *lines);
int		parse_rgb(char const *str, u_int *value);
int		is_rgb(char const *str);
int		parsing_map(t_cub *cub, t_line *lines);

int		grid_values_check(char **grid);
int		grid_stretch_lines(char **grid);
int		grid_wall_check(char **grid);

int		line_from_str(t_line *line, char *str);
int		count_spaces(char const *str, int start);
t_line	*find_line_by_key(t_line *lines, char const *key);
void	free_lines(t_line *lines);
void	free_line(void *ptr);
void	ft_strtrim_inplace(char *str);

int		ft_str_endswith(const char *s, const char *suffix);

#endif
