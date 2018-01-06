/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:48:29 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/20 18:48:31 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*tail;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		tail = malloc(sizeof(size_t));
		if (tail == NULL)
			return (NULL);
		tail = f(lst);
		if (!new)
		{
			new = tail;
			current = tail;
		}
		else
		{
			current->next = tail;
			current = current->next;
		}
		lst = lst->next;
	}
	return (new);
}
