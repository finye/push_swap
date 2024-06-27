/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:36:31 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/09 20:43:55 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parameters
	lst:  The address of a pointer to a node.
	f:    The address of the function used to iterate on
		  the list.
	del:  The address of the function used to delete
		  the content of a node if needed.
Return value
	The new list.
	NULL if the allocation fails.
External functs.
	malloc, free
Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.  Creates a new
	list resulting of the successive applications of
	the function ’f’.  The ’del’ function is used to
	delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	void	*fcontent;

	new_list = NULL;
	while (lst)
	{
		fcontent = f(lst->content);
		temp = ft_lstnew(fcontent);
		if (temp == NULL)
		{
			ft_lstclear(&new_list, del);
			del(fcontent);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
