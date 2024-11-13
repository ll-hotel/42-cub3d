/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:21:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/11/13 01:50:16 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "parsing.h"

int	parsing_colours(t_cube *cube, t_line *lines)
{
	t_line *const	f_colour = find_line_by_key(lines, "F");
	t_line *const	c_colour = find_line_by_key(lines, "C");

	if (!f_colour || !f_colour->value)
		ft_dprintf(2, "Error\nRGB value not found for floor colour!\n");
	else if (find_line_by_key(f_colour + 1, "F") != 0)
		ft_dprintf(2, "Error\nDuplicate key F\n");
	else if (!c_colour || !c_colour->value)
		ft_dprintf(2, "Error\nRGB value not found for ceiling colour!\n");
	else if (find_line_by_key(c_colour + 1, "C") != 0)
		ft_dprintf(2, "Error\nDuplicate key C\n");
	else
	{
		if (!is_rgb(f_colour->value))
			ft_dprintf(2, "Error\nWrong floor colour value: expected RGB\n");
		else if (!is_rgb(c_colour->value))
			ft_dprintf(2, "Error\nWrong ceiling colour value: expected RGB\n");
		else if (parse_rgb(f_colour->value, &cube->f_colour) && \
				(parse_rgb(c_colour->value, &cube->c_colour)))
			return (1);
	}
	return (0);
}
