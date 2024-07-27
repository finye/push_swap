/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:17:01 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/26 18:51:44 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The atol() function converts the initial portion of the string pointed to
     by str to long integer representation.
*/
long	ft_atol(const char *str)
{
	int		sign;
	long	number;
	long	check;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		check = number;
		number = number * 10 + (*str - '0');
		if (number / 10 != check && sign > 0)
			return (LONG_MAX);
		if (number / 10 != check && sign < 0)
			return (LONG_MIN);
		str++;
	}
	return (sign * number);
}
