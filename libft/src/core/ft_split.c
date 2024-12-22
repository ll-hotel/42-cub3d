/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:47:41 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/18 11:24:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "ptr.h"
#include <stdlib.h>

static int	count_words(const char *str, char c);
static int	wordlen(const char *str, int start, char c);

char	**ft_split(const char *str, char c)
{
	int		words_num;
	char	**words;
	int		word_index;
	int		word_len;
	int		i;

	if (str == NULL)
		return (0);
	words_num = count_words(str, c);
	words = malloc((words_num + 1) * sizeof(*words));
	if (words == NULL)
		return (0);
	i = 0;
	word_index = 0;
	while (word_index < words_num)
	{
		word_len = wordlen(str, i, c);
		words[word_index] = ft_substr(str, i, word_len);
		if (words[word_index] == NULL)
			return (ft_free2((void **)words, free));
		i += word_len;
		word_index += 1;
	}
	words[words_num] = NULL;
	return (words);
}

static int	skip_separators(const char *str, int start, char c)
{
	int	i;

	if (str == NULL || c == 0)
		return (0);
	i = 0;
	while (str[start + i] != 0 && str[start + i] == c)
		i += 1;
	return (i);
}

static int	wordlen(const char *str, int start, char c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[start + i] != 0 && str[start + i] != c)
		i += 1;
	return (i);
}

static int	count_words(const char *str, char c)
{
	int	counter;
	int	i;

	if (str == NULL)
		return (-1);
	if (c == 0)
		return (1);
	counter = 0;
	i = 0;
	while (str[i])
	{
		i += skip_separators(str, i, c);
		if (str[i] != 0)
			counter += 1;
		i += wordlen(str, i, c);
	}
	return (counter);
}
