/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:42:05 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/25 16:43:47 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cube_error(char *__message)
{
	ft_putstr_fd("Error\n", 2);
	if (__message)
		ft_putstr_fd(__message, 2);
	return (0);
}
