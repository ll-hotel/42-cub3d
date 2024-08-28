/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:22:04 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 15:50:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_lst	*lst_at(t_lst_head *lst_head, unsigned long i)
{
	t_lst	*lst_elt;

	lst_elt = lst_head->first;
	while (i-- > 0 && lst_elt)
		lst_elt = lst_elt->next;
	return (lst_elt);
}
