/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:24:46 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/15 16:03:57 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VEC_H
# define FT_VEC_H

typedef struct s_vector	t_vec;

struct	s_vector
{
	void			*array;
	unsigned long	size;
	unsigned long	elem_size;
	unsigned long	allocated_size;
};

void	vec_new(t_vec *vec, unsigned long elem_size);
void	*vec_addback(t_vec *vec, void *elem);
void	*vec_at(t_vec *vec, unsigned long i);
void	vec_clear(t_vec *vec, void (*del)(void *));

#endif
