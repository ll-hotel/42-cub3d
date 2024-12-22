/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:15:45 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/05/10 23:50:48 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst	*lst_get_last(t_lst_head *lst)
{
	t_lst	*element;

	element = lst->first;
	if (element)
		while (element->next)
			element = element->next;
	return (element);
}
