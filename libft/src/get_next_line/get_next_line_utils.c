/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:18:14 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 15:07:40 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	gnl_memcpy(void *dest, void *src, u_long size)
{
	if (size & 1)
		*((char *)dest++) = *((char *)src++);
	if (size & 2)
		*((short *)dest) = *((short *)src);
	dest += (size & 2);
	src += (size & 2);
	if (size & 4)
		*((int *)dest) = *((int *)src);
	dest += (size & 4);
	src += (size & 4);
	size >>= 3;
	while (size--)
	{
		*((long *)dest) = *((long *)src);
		dest += 8;
		src += 8;
	}
}

void	*gnl_realloc(void *p, u_long old_size, u_long size)
{
	void	*new_p;

	new_p = malloc(size);
	if (new_p)
		gnl_memcpy(new_p, p, old_size);
	free(p);
	return (new_p);
}

u_long	gnl_strichr(char *str, int c)
{
	u_long	i;

	i = 0;
	while (str[i] && str[i] != c)
		i += 1;
	return (i);
}
