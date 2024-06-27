/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:06:13 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 16:41:23 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer
     may subsequently be used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned
*/
static char	*ft_strcpy(const char *src, char *dest)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc((sizeof(char) * ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	else
		return (ft_strcpy(s1, dup));
}
