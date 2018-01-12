/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:28:32 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/11 15:29:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstreverse(t_list **beg_lst)
{
	t_list	*tmp;
	t_list	*list;

	tmp = NULL;
	list = NULL;
	if (*beg_lst == NULL)
		return ;
	while ((*beg_lst)->next)
	{
		tmp = (*beg_lst)->next;
		(*beg_lst)->next = list;
		list = *beg_lst;
		*beg_lst = tmp;
	}
	(*beg_lst)->next = list;
}
