/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/08/06 01:47:05 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

void	clock_init(void);
u_long	clock_get_mtime(void);

int	main(int argc, const char *argv[])
{
	t_cube	cube;

	if (argc != 2)
	{
		write(2, "cub3D: bad number of arguments\n", 32);
		return (1);
	}
	ft_bzero(&cube, sizeof(cube));
	if (!init_cube(&cube, argv[1]))
		return (1);
#if 1
	printf("height: %d\nwidth: %d\n", (int)cube.map.heigth, (int)cube.map.width);
	printf("player: (%d, %d)\n", (int)cube.player.pos.x, (int)cube.player.pos.y);
	for (int i = 0; i < cube.map.heigth; i++)
		printf("%s\n", cube.map.cells[i]);
	struct timeval tv_start, tv;
	printf("Starting frame computing...\n");
	gettimeofday(&tv_start, 0);
	// for (int x,y=0; y < SCREEN_HEIGHT; y++)
	// 	for (x = 0; x < SCREEN_WIDTH; x++)
	// 		img_put_pixel(&cube.mlx.img, y, x, 0xffffff);
	// cube_put_image(&cube);
	cube_render(&cube);
	gettimeofday(&tv, 0);
	printf("New frame displayed in %lu.%lus\n", (tv.tv_sec - tv_start.tv_sec), (tv.tv_usec - tv_start.tv_usec) % 1000000);
	usleep(1000000 * 2);
#endif
	destroy_cube(&cube);
	return (0);
}
