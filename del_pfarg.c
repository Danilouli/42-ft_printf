/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pfarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:12:03 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/29 15:29:14 by schmurz          ###   ########.fr       */
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
