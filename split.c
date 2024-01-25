/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:13 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/24 15:56:16 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wordcount(char *str, char sep)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == sep && *str)
			str++;
		while (*str != sep && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	int			i;
	int			len;
	char		*next_str;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split(char *str, char separator)
{
	int		num_of_words;
	int		i;
	char	**ptr;

	i = 0;
	num_of_words = wordcount(str, separator);
	if (!num_of_words)
		return (NULL);
	ptr = malloc(sizeof(char *) * (size_t)(num_of_words + 2));
	if (!ptr)
		return (NULL);
	while (num_of_words-- >= 0)
	{
		if (i == 0)
		{
			ptr[i] = malloc(sizeof(char));
			if (!ptr[i])
				return (NULL);
			ptr[i++][0] = '\0';
			continue ;
		}
		ptr[i++] = get_next_word(str, separator);
	}
	ptr[i] = NULL;
	return (ptr);
}
