/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pfarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:12:03 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/30 16:44:05 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			del_gpfargs(t_list **head)
{
	t_list *k;

	while ((*head))
	{
		free(((t_pfargs*)((*head)->content))->value);
		free((*head)->content);
		k = (*head);
		(*head) = (*head)->next;
		free(k);
	}
	g_pfargs = 0;
	return (1);
}
