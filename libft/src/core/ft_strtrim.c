/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:22:21 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 19:28:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include <stdlib.h>

static _Bool	_is_in_set(char c, const char *_set)
{
	size_t	i;

	i = 0;
	while (_set[i])
		if (_set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	end = ft_strlen(str);
	if (end == 0)
		return (NULL);
	start = 0;
	while (str[start] && _is_in_set(str[start], set))
		start += 1;
	end -= 1;
	while (end > start && _is_in_set(str[end], set))
		end -= 1;
	new_str = ft_calloc(end - start + 1, sizeof(*new_str));
	if (new_str)
		ft_memmove(new_str, &str[start], end - start + 1);
	return (new_str);
}

char	*ft_strtrim_inplace(char *str, const char *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(str);
	if (end == 0)
		return (str);
	start = 0;
	while (str[start] && _is_in_set(str[start], set))
		start += 1;
	end -= 1;
	while (end > start && _is_in_set(str[end], set))
		end -= 1;
	str[end] = 0;
	ft_memmove(str, &str[start], end - start + 1);
	return (str);
}
