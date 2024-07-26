/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:26:49 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/26 16:30:45 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	maxc(char a, char b)
{
	return (a * (a >= b) + b * (a < b));
}

short	maxs(short a, short b)
{
	return (a * (a >= b) + b * (a < b));
}

int	maxi(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

long	maxl(long a, long b)
{
	return (a * (a >= b) + b * (a < b));
}
