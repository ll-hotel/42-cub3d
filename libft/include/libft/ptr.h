/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:32:14 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/16 18:01:52 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTR_H
# define PTR_H

void	*ft_realloc(void *p, unsigned long old_size, unsigned long n);
void	*ft_free2(void **p, void (*_free)(void *));
#endif
