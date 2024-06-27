/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:19:58 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 20:17:51 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
	strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in practice
     this should not happen as it means that either dstsize is incorrect or that
     dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.
	 
RETURN VALUES
	the strlcpy() and strlcat() functions return the total
    length of the string they tried to create.  For strlcpy() that means the
    length of src.  For strlcat() that means the initial length of dst plus the
    length of src.

     If the return value is >= dstsize, the output string has been truncated.  It
     is the caller's responsibility to handle this.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	off_set;
	size_t	src_i;

	dest_len = 0;
	src_len = 0;
	src_i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if ((!dst || !src) && !dstsize)
		return (0);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	off_set = dest_len;
	while (src[src_i] != '\0' && (src_i < dstsize - dest_len - 1))
	{
		dst[off_set] = src[src_i];
		off_set++;
		src_i++;
	}
	dst[off_set] = '\0';
	return (dest_len + src_len);
}
