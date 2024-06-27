/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:04:47 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/08 11:43:33 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isdigit() function tests for a decimal digit character.
	 
RETURN VALUES
     The isdigit() and isnumber() functions return zero if the character tests
     false and return non-zero if the character tests true.	 
*/
int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}
