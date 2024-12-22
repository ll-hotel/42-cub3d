/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:55:07 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 16:22:04 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst	*lst_map(t_lst_head *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst_head	*map_lst;
	t_lst_head	tmp_lst;

	map_lst = &tmp_lst;
	map_lst->first = 0;
	while (lst->first)
	{
		map_lst->first = f(lst->first);
		if (!map_lst->first)
		{
			lst_clear(map_lst, del);
			return (0);
		}
		map_lst = map_lst->next;
	}
	return (map_lst->first);
}
