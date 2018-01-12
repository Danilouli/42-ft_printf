/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:29:22 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/11 18:10:07 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"
#include <stdio.h>

int is_printf_arg(const char *pt)
{
	return(*pt == '%' && *(pt + 1) && *(pt + 1) != '%');
}

void count_printf_args(const char *form)
{
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
				pfargs.len = ft_strlen(pfargs.value);
				ft_lstadd(&g_pfargs, ft_lstnew((&pfargs), sizeof(t_pfargs*) + sizeof(char*) + 1 + sizeof(int)));
			}
		}
		j = (form[j] == '%' && form[j + 1] == '%') ? j + 2 : j + 1;
	}
	ft_lstreverse(&g_pfargs);
}
