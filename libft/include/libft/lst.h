/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:35:45 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/15 16:04:16 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst_head	t_lst_head;
typedef struct s_lst		t_lst;

struct	s_lst_head
{
	union
	{
		t_lst		*first;
		t_lst_head	*next;
	};
};

struct	s_lst
{
	t_lst	*next;
};

void	lst_add_back(t_lst_head *lst, t_lst *elt);
void	lst_add_front(t_lst_head *lst, t_lst *elt);
void	lst_clear(t_lst_head *lst, void (*f)(void *));
void	lst_delone(t_lst_head *lst, void (*f)(void *));
long	lst_len(t_lst_head *lst);
t_lst	*lst_at(t_lst_head *lst, unsigned long i);
t_lst	*lst_next(t_lst_head *lst);
t_lst	*lst_last(t_lst_head *lst);

void	lst_iter(t_lst_head *lst, void (*f)(void *));
t_lst	*lst_map(t_lst_head *lst, void *(*f)(void *), void (*del)(void *));

#endif
