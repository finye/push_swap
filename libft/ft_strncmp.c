/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:11:33 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 21:05:08 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
  The strcmp() and strncmp() functions lexicographically compare the null-termi-
  nated strings s1 and s2.

  The strncmp() function compares not more than n characters.  Because strncmp()
  is designed for comparing strings rather than binary data, characters that
  appear after a `\0' character are not compared.
  
RETURN VALUES
  The strcmp() and strncmp() functions return an integer greater than, equal to,
  or less than 0, according as the string s1 is greater than, equal to, or less
  than the string s2.  The comparison is done using unsigned characters, so that
  `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
