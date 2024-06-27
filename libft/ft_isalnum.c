/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:27:02 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 11:45:47 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isalnum() function tests for any character for which isalpha(3) or
     isdigit(3) is true.
	 
RETURN VALUES
     The isalnum() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/
int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (1);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
