/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:38:30 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 20:18:03 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Description
	Returns the last node of the list.
Parameters
	lst:  The beginning of the list.
Return value
	Last node of the list
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			last_node = lst;
		lst = lst->next;
	}
	return (last_node);
}
