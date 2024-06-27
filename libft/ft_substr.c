/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:18:29 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 17:03:08 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
PARAMETERS
	s:  The string from which to create the substring.
	start:  The start index of the substring in the
			string ’s’.
	len:  The maximum length of the substring.
RETURN VALUE
	The substring.
	NULL if the allocation fails.
External functs.
	malloc
DESCRIPTION
	Allocates (with malloc(3)) and returns a substring
	from the string ’s’.
	The substring begins at index ’start’ and is of
	maximum size ’len’.
	*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - (size_t)start))
		len = ft_strlen(s) - (size_t)start;
	substr = (char *)malloc((sizeof(char) * len) + 1);
	if (substr == NULL)
		return (NULL);
	if ((size_t)start <= ft_strlen(s))
		s += start;
	temp = substr;
	while (*s && len)
	{
		*substr++ = *s++;
		len--;
	}
	*substr = '\0';
	return (temp);
}
