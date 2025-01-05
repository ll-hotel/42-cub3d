/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:03:44 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 18:13:46 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"
#include "libft/ft_dprintf.h"
#include "parsing.h"

int	parse_rgb(char const *str, t_uint *value)
{
	int	red;
	int	green;
	int	blue;
	int	i;

	i = count_spaces(str, 0);
	red = ft_atoi(&str[i]);
	i += ft_strchr(&str[i], ',') - &str[i] + 1;
	i += count_spaces(str, i);
	green = ft_atoi(&str[i]);
	i += ft_strchr(&str[i], ',') - &str[i] + 1;
	i += count_spaces(str, i);
	blue = ft_atoi(&str[i]);
	if (red > 255)
		ft_dprintf(2, "Error\nWrong red RGB value %d (max. 255)\n", red);
	else if (green > 255)
		ft_dprintf(2, "Error\nWrong green RGB value %d (max. 255)\n", green);
	else if (blue > 255)
		ft_dprintf(2, "Error\nWrong blue RGB value %d (max. 255)\n", blue);
	else
	{
		*value = (red << 16) | (green << 8) | blue;
		return (1);
	}
	return (0);
}

static int	is_valid_red(char const *str, int *size)
{
	int	offset;
	int	num_len;

	offset = count_spaces(str, 0);
	num_len = 0;
	while (ft_isdigit(str[offset + num_len]))
		num_len++;
	offset += num_len;
	offset += count_spaces(str, offset);
	if (str[offset] != ',')
		return (0);
	*size = offset + 1;
	return (num_len >= 1);
}

static int	is_valid_green(char const *str, int *size)
{
	int	offset;
	int	num_len;

	offset = count_spaces(str, 0);
	num_len = 0;
	while (ft_isdigit(str[offset + num_len]))
		num_len++;
	offset += num_len;
	offset += count_spaces(str, offset);
	if (str[offset] != ',')
		return (0);
	*size += offset + 1;
	return (num_len >= 1);
}

static int	is_valid_blue(char const *str)
{
	int	offset;
	int	num_len;

	offset = count_spaces(str, 0);
	num_len = 0;
	while (ft_isdigit(str[offset + num_len]))
		num_len++;
	offset += num_len;
	offset += count_spaces(str, offset);
	if (str[offset] != 0)
		return (0);
	return (num_len >= 1);
}

int	is_rgb(char const *str)
{
	int	offset;

	offset = 0;
	if (!is_valid_red(str, &offset))
		return (0);
	if (!is_valid_green(str + offset, &offset))
		return (0);
	if (!is_valid_blue(str + offset))
		return (0);
	return (1);
}
