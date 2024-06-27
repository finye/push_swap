/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:16 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 20:49:35 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 DESCRIPTION
	The calloc() function contiguously allocates enough space for count
	objects that are size bytes of memory each and returns a pointer to
	the allocated memory. The allocated memory is filled with bytes of
	value zero.
RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), and
     valloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer.	
	*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	if (count && (SIZE_MAX / count) < size)
		return (NULL);
	i = 0;
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
