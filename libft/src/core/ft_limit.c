/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:14:14 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/20 17:42:37 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_limit(long value, long lower_bound, long upper_bound)
{
	if (value < lower_bound)
		return (lower_bound);
	if (value > upper_bound)
		return (upper_bound);
	return (value);
}
