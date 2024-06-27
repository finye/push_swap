/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:14 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 11:41:20 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isalpha() function tests for any character for which isupper(3) or
     islower(3) is true.
	 
RETURN VALUES
     The isalpha() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/
int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}
