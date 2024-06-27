/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:59:50 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 19:11:03 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
	 The two strings may overlap;
     the copy is always done in a non-destructive manner.
RETURN VALUES
     The memmove() function returns the original value of dst.
	 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (dst <= src)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else if (dst > src)
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}
