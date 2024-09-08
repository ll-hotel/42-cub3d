/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:24:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/08 20:38:33 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2F_H
# define VEC2F_H

typedef struct s_vec2f	t_vec2f;

struct	s_vec2f
{
	float	x;
	float	y;
};

t_vec2f	vec2f(float x, float y);
t_vec2f	vec2f_add(t_vec2f v1, t_vec2f v2);
t_vec2f	vec2f_sub(t_vec2f v1, t_vec2f v2);
t_vec2f	vec2f_scal(t_vec2f v, float scalar);

#endif
