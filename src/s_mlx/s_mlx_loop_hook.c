/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_loop_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:08:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:51 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <s_mlx.h>

void	s_mlx_loop_hook(const t_mlx *mlx, void (*funct)(), void *param)
{
	mlx_loop_hook(mlx->mlx_ptr, (int (*)())funct, param);
}
