/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:33:14 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 15:33:53 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated
	string needle in the string haystack, where not more than len characters 
	are searched.Characters that appear after a `\0' character are not searched.
RETURN VALUES
     If needle is an empty string, haystack is returned; 
	 if needle occurs nowhere in haystack, NULL is returned;
	 otherwise a pointer to the first character of the first 
	 occurrence of needle is returned.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (len > i && haystack[i] != '\0')
	{
		j = 0;
		while (len > (i + j) && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
