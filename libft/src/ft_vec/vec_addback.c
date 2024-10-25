/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:26:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/20 17:41:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_basics.h"
#include "ft_ptr.h"
#include "ft_vec.h"

void	*vec_addback(t_vec *vec, void *elem)
{
	if (vec->size >= vec->allocated_size)
	{
		vec->allocated_size += 1;
		vec->allocated_size *= 1.5;
		vec->array = ft_realloc(vec->array, vec->size * vec->elem_size, \
				vec->allocated_size * vec->elem_size);
	}
	if (vec->array == (void *)0)
		return (0);
	if (vec->elem_size > 8)
		ft_memmove(vec_at(vec, vec->size), elem, vec->elem_size);
	else
		ft_memmove(vec_at(vec, vec->size), &elem, vec->elem_size);
	vec->size += 1;
	return (vec_at(vec, vec->size - 1));
}
