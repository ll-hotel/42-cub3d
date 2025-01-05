/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:56:33 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 17:46:57 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "parsing.h"
#include <stdlib.h>

int	line_from_str(t_line *line, char *str)
{
	int	i;

	ft_memset(line, 0, sizeof(*line));
	if (str == NULL)
		return (0);
	line->ptr = str;
	line->key = &line->ptr[count_spaces(line->ptr, 0)];
	if (ft_isdigit(line->key[0]))
		return (1);
	i = 0;
	while (line->key[i] && line->key[i] != ' ')
		i += 1;
	if (line->key[i] == ' ')
	{
		line->key[i] = 0;
		i += count_spaces(line->key, i + 1) + 1;
		if (line->key[i] != 0)
			line->value = &line->key[i];
	}
	return (1);
}

t_line	*find_line_by_key(t_line *lines, char const *key)
{
	int	i;

	i = 0;
	while (lines[i].ptr != NULL)
	{
		if (lines[i].key != NULL && ft_strcmp(lines[i].key, key) == 0)
			return (&lines[i]);
		i += 1;
	}
	return (NULL);
}

int	count_spaces(char const *str, int start)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[start + i] == ' ')
		i += 1;
	return (i);
}

void	free_line(void *ptr)
{
	t_line *const	line = ptr;

	if (line->ptr)
		free(line->ptr);
}

void	free_lines(t_line *lines)
{
	int	i;

	i = 0;
	while (lines[i].ptr != NULL)
		free(lines[i++].ptr);
	free(lines);
}
