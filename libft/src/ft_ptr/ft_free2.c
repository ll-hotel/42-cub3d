/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:38:17 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 15:42:38 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free2(void **p, void (*_free)(void *))
{
	int	i;

	if (!p)
		return (NULL);
	i = 0;
	while (p[i] != NULL)
		_free(p[i++]);
	free(p);
	return (NULL);
}
