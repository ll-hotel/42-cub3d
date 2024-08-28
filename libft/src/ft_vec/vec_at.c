/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:32:32 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/20 17:51:41 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

void	*vec_at(t_vec *vec, unsigned long i)
{
	if (i > vec->size || !vec->array)
		return (0);
	return (vec->array + i * vec->elem_size);
}
