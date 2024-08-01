/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:38:31 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/29 18:47:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	append_line(t_vec *file, char *line);

int	read_file(const int fd, char ***lines)
{
	t_vec	file;
	char	*line;

	vec_new(&file, sizeof(**lines));
	line = get_next_line(fd);
	while (line && append_line(&file, line))
	{
		line = get_next_line(fd);
	}
	if (!vec_addback(&file, NULL))
	{
		vec_clear(&file, free);
		return (0);
	}
	*lines = file.array;
	return (1);
}

static int	append_line(t_vec *file, char *line)
{
	if (ft_strrchr(line, '\n'))
		*ft_strrchr(line, '\n') = 0;
	if (!vec_addback(file, line))
	{
		vec_clear(file, free);
		return (0);
	}
	return (1);
}
