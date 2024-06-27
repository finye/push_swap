/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:28:57 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 15:21:34 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The memcmp() function compares byte string s1 against byte string
     s2.  Both strings are assumed to be n bytes long.
	 
RETURN VALUES
     The memcmp() function returns zero if the two strings are identi-
     cal, otherwise returns the difference between the first two differ-
     ing bytes (treated as unsigned char values, so that `\200' is
     greater than `\0', for example).
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
