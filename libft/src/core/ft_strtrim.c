/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:22:21 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/05 22:27:42 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	end = ft_strlen(str);
	if (end == 0)
		return (NULL);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start += 1;
	end -= 1;
	while (end > start && ft_strchr(set, str[end]))
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
	while (str[start] && ft_strchr(set, str[start]))
		start += 1;
	end -= 1;
	while (end > start && ft_strchr(set, str[end]))
		end -= 1;
	str[end + 1] = 0;
	ft_memmove(str, &str[start], end - start + 1);
	return (str);
}
