/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sptr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:21:08 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 18:24:50 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sptr	*sptr_cpy(t_sptr *sptr)
{
	if (sptr->ptr)
		sptr->refs += 1;
	return (sptr);
}

void	sptr_free(t_sptr *sptr, void (*__free)(void *))
{
	if (sptr->refs)
		sptr->refs -= 1;
	if (sptr->refs == 0 && sptr->ptr && __free)
	{
		__free(sptr->ptr);
		sptr->ptr = 0;
	}
}
