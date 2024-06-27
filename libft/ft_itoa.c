/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:33:55 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 18:24:22 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.
RETURN VALUE
	The string representing the integer.
	NULL if the allocation fails.
PARAM
	n: the integer to convert.
*/
static unsigned int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*case_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	long			nb;

	len = count_digit(n) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	case_null(nb, str);
	str[--len] = '\0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
