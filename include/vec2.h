/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:24:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/06 01:32:17 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef struct s_vec2	t_vec2;

struct	s_vec2
{
	float	x;
	float	y;
};

t_vec2	*vec2_new(const float x, const float y);
t_vec2	vec2_add(const t_vec2 a, const t_vec2 b);
float	vec2_dotp(const t_vec2 a, const t_vec2 b);

#endif
