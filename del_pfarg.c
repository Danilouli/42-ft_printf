/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pfarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:12:03 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/30 14:15:54 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void del_pfarg_content(t_pfargs *pfargs) {
  free(pfargs->value);
  pfargs->value = NULL;
  pfargs->type = 0;
  pfargs->len = 0;
  pfargs->index = 0;
}

void del_pfarg(void *content, size_t size)
{
  size = 0;
  del_pfarg_content((t_pfargs*)content);
  free(content);
  content = NULL;
}

int del_gpfargs(t_list **head)
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
	return(1);
}
