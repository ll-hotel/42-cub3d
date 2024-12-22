/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:01:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/18 14:27:26 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n && s1[i] && s1[i] == s2[i])
		i++;
	return ((n > 0) * ((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
