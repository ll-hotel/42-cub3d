/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:09:16 by ll-hotel          #+#    #+#             */
/*   Updated: 2025/01/08 15:09:23 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <s_mlx.h>

void	s_mlx_key_hook(const t_mlx *mlx, void (*funct)(), void *param)
{
	mlx_key_hook(mlx->win_ptr, (int (*)())funct, param);
}
