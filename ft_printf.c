/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:23:19 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/23 19:14:15 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libftprintf.h"
#include "ft_printf.h"

// int printf(const char *form, ...)
// {
//
// }

int add_n(int nbop, ...)
{
	int i, s = 0;
	va_list(ap);
	va_start(ap, nbop);
	for (i = 1; i <= nbop; i++)
	{
		s += va_arg(ap,int);
	}
	va_end(ap);
	return(s);
}

int	main(int argc, char **argv)
{
	// t_list *keep;
  //
	// keep = g_pfargs;
	if (argc < 2)
		return (0);
	count_printf_args(argv[1]);
	//printf("%zu\n",ft_lstlen(g_pfargs));
	printf("%s\n",((t_pfargs*)(g_pfargs->content))->value);
	while (g_pfargs)
	{
		printf("%s\n",((t_pfargs*)(g_pfargs->content))->value);
		g_pfargs = g_pfargs->next;
	}
	return(0);
}
