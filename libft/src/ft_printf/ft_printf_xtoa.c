/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:43:57 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/20 17:50:43 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_basics.h"
#include "ft_math.h"

char	*ft_xtoa(unsigned long value, short ox, short capital)
{
	const char *const	set = "0123456789abcdef";
	short				i;
	char				*a;

	i = ft_log_b(value, 16) + 1;
	a = (char *)ft_calloc(i + 1 + (2 * ox), sizeof(char));
	if (!a)
		return (0);
	capital &= 1;
	capital *= 32;
	while (i)
	{
		a[(2 * ox) + --i] = set[value % 16] - capital * ((value % 16) > 9);
		value /= 16;
	}
	if (ox)
	{
		a[0] = '0';
		a[1] = 'x' - capital;
	}
	return (a);
}
