/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:56:33 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/26 16:13:54 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_line(char **lines, const char *prefix)
{
	const int	prefix_len = ft_strlen(prefix);
	int			i;

	i = -1;
	while (lines[++i])
		if (ft_strncmp(lines[i], prefix, prefix_len) == 0)
			return (lines[i]);
	return (0);
}
