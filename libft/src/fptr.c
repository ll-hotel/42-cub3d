/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fptr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:33 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/26 13:07:26 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_fptr	*fptr_new(u_long __size)
{
	t_fptr	*fptr;

	fptr = malloc(sizeof(*fptr));
	if (fptr)
	{
		if (!fptr_init(fptr, __size))
		{
			free(fptr);
			fptr = NULL;
		}
	}
	return (fptr);
}

void	*fptr_init(t_fptr *__fptr, u_long __size)
{
	if (!__fptr)
		return (NULL);
	__fptr->size = 0;
	__fptr->ptr = 0;
	if (__size > 0)
		__fptr->ptr = malloc(__size);
	if (__fptr->ptr)
		__fptr->size = __size;
	if (__size == 0 || __fptr->ptr != NULL)
		return (__fptr);
	return (NULL);
}

void	fptr_free(t_fptr *__fptr, void (*__free)(void *))
{
	if (__fptr->ptr)
		__free(__fptr->ptr);
	__fptr->ptr = 0;
	__fptr->size = 0;
}
