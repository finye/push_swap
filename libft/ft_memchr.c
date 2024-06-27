/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:25:51 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:41 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
    The memchr() function locates the first occurrence of c (converted to an
    unsigned char) in string s.
	 
RETURN VALUES
    The memchr() function returns a pointer to the byte located, or NULL if no
    such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;

	copy = (unsigned char *)s;
	while (n > 0)
	{
		if (*copy == (unsigned char) c)
			return ((void *)copy);
		copy++;
		n--;
	}
	return (0);
}
