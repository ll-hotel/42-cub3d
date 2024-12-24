/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:21:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/23 19:41:33 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/ft_dprintf.h"
#include "parsing.h"

int	parsing_colours(t_cub *cub, t_line *lines)
{
	t_line *const	f_colour = find_line_by_key(lines, "F");
	t_line *const	c_colour = find_line_by_key(lines, "C");

	if (!f_colour || !f_colour->value)
		ft_dprintf(2, "Error\nRGB value not found for floor colour!\n");
	else if (!c_colour || !c_colour->value)
		ft_dprintf(2, "Error\nRGB value not found for ceiling colour!\n");
	else
	{
		if (!is_rgb(f_colour->value))
			ft_dprintf(2, "Error\nWrong floor colour value: expected RGB\n");
		else if (!is_rgb(c_colour->value))
			ft_dprintf(2, "Error\nWrong ceiling colour value: expected RGB\n");
		else if (parse_rgb(f_colour->value, &cub->colors[CO_FLOOR]) && \
				(parse_rgb(c_colour->value, &cub->colors[CO_CEILING])))
			return (1);
	}
	return (0);
}
