/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:42:05 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/11 19:08:52 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "mlx.h"

int	cube_error(char *__message)
{
	ft_putstr_fd("Error\n", 2);
	if (__message)
		ft_putstr_fd(__message, 2);
	return (0);
}

void	cube_put_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx.ptr, \
						cube->mlx.win, \
						cube->mlx.img.ptr, \
						0, 0);
}
