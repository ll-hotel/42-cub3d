/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:09:30 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:09:31 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./s_cub.h"

void	loop_hook(t_cub *cub);
void	key_hook(int keysym, t_cub *cub);

enum	e_block
{
	BL_FLOOR,
	BL_WALL,
	BL_NB,
};

#endif /* #ifndef CUB3D_H */
