/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:11:36 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 17:30:33 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
PARAMETERS
	s1:  The string to be trimmed.
	set: The reference set of characters to trim.
RETURN VALUE
	The trimmed string.
	NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		front = 0;
		rear = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		if (rear)
		{
			while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
				rear--;
		}
		str = (char *)malloc(sizeof(char) * (rear - front + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[front], rear - front + 1);
	}
	return (str);
}
