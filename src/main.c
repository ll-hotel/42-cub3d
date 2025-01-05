/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:07:36 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:39:30 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <libft/ft_dprintf.h>

int	main(int argc, const char *argv[])
{
	t_cub	cub;

	if (argc != 2)
	{
		ft_dprintf(2, "Error\nBad arguments\n");
		return (1);
	}
	if (s_cub_init(&cub, argv[1]))
		return (1);
	s_cub_run(&cub);
	s_cub_destroy(&cub);
	return (0);
}
