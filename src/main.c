/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:10 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/09/08 20:48:58 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_basics.h"
#include <unistd.h>
/*
#include <stdio.h>
#include <sys/time.h>

static void	debug(t_cube *cube)
{
	struct timeval	tv_start;
	struct timeval	tv;
	int				i;
	int				frame_nb;
	double			total_time;

	printf("height: %d\n", (int)cube->map.height);
	printf("width: %d\n", (int)cube->map.width);
	printf("player: (%d, %d)\n", (int)cube->player.pos.x, \
			(int)cube->player.pos.y);
	printf("floor colour: %x, ceiling colour: %x\n", cube->f_colour, \
			cube->c_colour);
	i = 0;
	while (i < cube->map.height)
		printf("%s\n", cube->map.cells[i++]);
	printf("Starting frame computing...\n");
	gettimeofday(&tv_start, 0);
	frame_nb = 0;
	while (frame_nb < 100)
	{
		cube_render(cube);
		usleep(500);
		frame_nb++;
	}
	gettimeofday(&tv, 0);
	total_time = (tv.tv_sec - tv_start.tv_sec) + \
				 ((tv.tv_usec - tv_start.tv_usec) % 1000000) / 10000000.f;
	printf("Displayed %d frames in %f seconds\n", frame_nb, total_time);
	printf("Around %f fps\n", 1.0 / (total_time / (double)frame_nb));
}
*/

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
	// debug(&cube);
	cube_render(&cube);
	cube_loop(&cube);
	destroy_cube(&cube);
	return (0);
}
