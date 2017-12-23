/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:27:50 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/23 19:13:06 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t len;
	t_list *keep;

	len = 0;
	keep = lst;
	if (!keep)
		return (0);
	while (keep->next)
	{
		len++;
		keep = keep->next;
	}
	return (len + 1);
}
