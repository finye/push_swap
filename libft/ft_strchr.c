/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:56:19 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 20:33:57 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
    The strchr() function locates the first occurrence of c (converted to a char)
    in the string pointed to by s.  The terminating null character is considered
    to be part of the string; therefore if c is `\0', the functions locate the
    terminating `\0'.
	 
RETURN VALUES
    The functions strchr() and strrchr() return a pointer to the located charac-
    ter, or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	else
		return (0);
}
