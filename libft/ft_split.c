/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:38:49 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 18:09:08 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
	Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array must end
	with a NULL pointer.
PARAMETERS
	s: The string to be split.
	c: The delimiter character.
EXTERNAL FUNCTS
	malloc, free
RETURN VALUE
	The array of new strings resulting from the split.
	NULL if the allocation fails.
 */
static size_t	count_words(char const *str, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == c) && str[i] != c)
			word++;
		i++;
	}
	return (word);
}

static void	free_mem(char **str, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_copy(char const *s, char c, char **str)
{
	size_t		i;
	const char	*ptr;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		ptr = s;
		while (*s && *s != c)
			s++;
		if (*ptr != '\0')
		{
			str[i] = ft_substr(ptr, 0, s - ptr);
			if (str[i] == NULL)
			{
				free_mem(str, i);
				return (NULL);
			}
			i++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word_count;

	word_count = 0;
	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	str = malloc((word_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[word_count] = NULL;
	if (ft_copy(s, c, str))
		return (str);
	return (NULL);
}
