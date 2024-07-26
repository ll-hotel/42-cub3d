/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umax.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:31 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/26 16:32:05 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

u_char	maxuc(u_char a, u_char b)
{
	return (a * (a >= b) + b * (a < b));
}

u_short	maxus(u_short a, u_short b)
{
	return (a * (a >= b) + b * (a < b));
}

u_int	maxui(u_int a, u_int b)
{
	return (a * (a >= b) + b * (a < b));
}

u_long	maxul(u_long a, u_long b)
{
	return (a * (a >= b) + b * (a < b));
}

void	*maxp(void *a, void *b)
{
	return ((void *)((u_long)a * (a >= b) + (u_long)b * (a < b)));
}
