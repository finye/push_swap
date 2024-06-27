/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:56:30 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 20:40:49 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strchr() function locates the last occurrence of c (converted to a char)
     in the string pointed to by s.  The terminating null character is considered
     to be part of the string; therefore if c is `\0', the functions locate the
     terminating `\0'.
	 
RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located charac-
     ter, or NULL if the character does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				last_occ;

	i = 0;
	last_occ = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			last_occ = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	if (last_occ == -1)
		return (0);
	return ((char *) s + last_occ);
}
