/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:30:14 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/24 18:13:09 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2f.h"

t_vec2f	vec2f(float x, float y)
{
	return ((t_vec2f){x, y});
}

t_vec2f	vec2f_add(t_vec2f v1, t_vec2f v2)
{
	return ((t_vec2f){v1.x + v2.x, v1.y + v2.y});
}

t_vec2f	vec2f_sub(t_vec2f v1, t_vec2f v2)
{
	return ((t_vec2f){v1.x - v2.x, v1.y - v2.y});
}

t_vec2f	vec2f_scal(t_vec2f v, float scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	return (v);
}
