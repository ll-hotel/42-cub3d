/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endswith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:43:29 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/26 14:52:27 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_endswith(const char *s1, const char *s2)
{
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);

	if (len2 > len1)
		return (0);
	return (ft_strncmp(s1 + len1 - len2, s2, len2) == 0);
}
