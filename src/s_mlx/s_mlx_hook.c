/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:09:32 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:09:41 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <s_mlx.h>

void	s_mlx_hook(const t_mlx *mlx, int x_event, void (*funct)(), void *param)
{
	mlx_hook(mlx->win_ptr, x_event, 0, (int (*)())funct, param);
}
