/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:22:06 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 13:27:29 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*keep;
	t_list	*new;
	t_list	*curr;

	if (!lst || !f)
		return (0);
	keep = 0;
	while (lst)
	{
		new = (*f)(lst);
		if (keep)
		{
			curr->next = new;
			curr = curr->next;
		}
		else
		{
			keep = new;
			curr = keep;
		}
		lst = lst->next;
	}
	return (keep);
}
