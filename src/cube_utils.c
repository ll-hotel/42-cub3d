/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:42:05 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/20 17:01:16 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include "ft_basics.h"

void	cube_put_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx.ptr, \
			cube->mlx.win, \
			cube->mlx.img.ptr, \
			0, 0);
}

void	ft_strtrim_inplace(char *str)
{
	int	start;
	int	length;
	int	end;

	if (str == (void *)0)
		return ;
	start = 0;
	while (str[start] == ' ')
		start += 1;
	end = start;
	while (str[end] != 0 && str[end] != ' ')
		end += 1;
	length = end - start;
	str[end] = 0;
	ft_memmove(str, &str[start], length);
}
