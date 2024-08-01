/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/29 23:58:47 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, const char *argv[])
{
	t_cube	cube;

	if (argc != 2)
	{
		write(2, "cub3D: bad number of arguments\n", 32);
		return (1);
	}
	ft_bzero(&cube, sizeof(cube));
	cube.mlx.ptr = mlx_init();
	if (!cube.mlx.ptr)
		return (2);
	if (!cube_parse_file(&cube, argv[1]))
		return (1);

#if 0
	ft_printf("height: %d\nwidth: %d\n", (int)cube.map.heigth, (int)cube.map.width);
	ft_printf("player: (%d, %d)\n", (int)cube.player.x, (int)cube.player.y);
	for (int i = 0; i < cube.map.heigth; i++)
		ft_printf("%s\n", cube.map.cells[i]);
	for (int i = 0; i < cube.map.heigth; i++)
		free(cube.map.cells[i]);
	free(cube.map.cells);
#endif

	return (0);
}
