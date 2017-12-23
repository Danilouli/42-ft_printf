/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:29:22 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/23 19:20:38 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"
#include <stdio.h>

void count_printf_args(char *form) {
	int j;
	int c;
	t_pfargs pfargs;

	j = 0;
	c = 1;
	while (form[j])
	{
		if(form[j] == '%' && form[j + 1] && form[j + 1] != '%')
		{
			c = 1;
			while (form[j + c] && !ft_isalpha(form[j + c]) && form[j + c] != '%')
				c++;
			if (!form[j + c])
				break;
			if (form[j + c] != '%')
			{
				pfargs.value = ft_strsub(form, j, c + 1);
				pfargs.type = form[j + c];
				ft_lstadd(&g_pfargs, ft_lstnew((&pfargs), sizeof(t_pfargs*)));
			}
		}
		j = (form[j] == '%' && form[j + 1] == '%') ? j + 2 : j + 1;
	}
}
