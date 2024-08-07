/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:30:14 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/06 01:33:08 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include <stdlib.h>

t_vec2	*vec2_new(const float x, const float y)
{
	t_vec2	*vec2;

	vec2 = malloc(sizeof(*vec2));
	if (vec2)
	{
		vec2->x = x;
		vec2->y = y;
	}
	return (vec2);
}

t_vec2	vec2_add(const t_vec2 a, const t_vec2 b)
{
	return ((t_vec2){a.x + b.x, a.y + b.y});
}

float	vec2_dotp(const t_vec2 a, const t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}
