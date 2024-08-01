/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:21:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/30 00:00:05 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "include/basics.h"
#include "libft.h"

static int	check_founds(char *f_colour, char *c_colour);
static int	check(char *colour);
static int	check_for_rgb_value(char *value);
static int	store_colour(char *colour);

int	parsing_colours(t_cube *cube, char **lines)
{
	char *const	f_colour = find_line(lines, "F ");
	char *const	c_colour = find_line(lines, "C ");

	if (!check_founds(f_colour, c_colour))
		return (0);
	if (!check(f_colour) || !check(c_colour))
		return (0);
	cube->f_colour = store_colour(f_colour);
	cube->c_colour = store_colour(c_colour);
	return (1);
}

static int	check_founds(char *f_colour, char *c_colour)
{
	if (!f_colour)
		return (cube_error("Could not find Floor colour\n"));
	if (!c_colour)
		return (cube_error("Could not find Ceiling colour\n"));
	return (1);
}

static int	check(char *colour)
{
	int	digit_number;

	digit_number = check_for_rgb_value(colour + 2);
	if (!digit_number)
		return (0);
	colour += 2 + digit_number;
	if (*colour != ',')
		return (cube_error("Unexpected character in RGB value\n"));
	digit_number = check_for_rgb_value(colour + 1);
	if (!digit_number)
		return (0);
	colour += 1 + digit_number;
	if (*colour != ',')
		return (cube_error("Unexpected character in RGB value\n"));
	digit_number = check_for_rgb_value(colour + 1);
	if (!digit_number)
		return (0);
	colour += 1 + digit_number;
	if (*colour != 0)
		return (cube_error("Unexpected character after RGB value\n"));
	return (1);
}

static int	check_for_rgb_value(char *value)
{
	int	digit_number;

	digit_number = 0;
	while (ft_isdigit(value[digit_number]))
		digit_number += 1;
	if ((0 == digit_number || digit_number > 3) || ft_atoi(value) > 255)
	{
		value[digit_number] = 0;
		ft_dprintf(2, "Error\nWrong value for RGB: %s\n", value);
		return (0);
	}
	return (digit_number);
}

static int	store_colour(char *colour)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(colour);
	while (*colour != ',')
		colour += 1;
	green = ft_atoi(colour);
	while (*colour != 0)
		colour += 1;
	blue = ft_atoi(colour);
	return (red << 24 | green << 16 | blue);
}
