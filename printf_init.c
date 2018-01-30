/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:29:22 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:48 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			mult_flag_arg(const char *format)
{
	static char	mflags[2] = ".#";
	int			i;

	i = 0;
	while (mflags[i])
	{
		if (ft_numberchars(format, mflags[i]) > 1)
			return (1);
		i++;
	}
	return (0);
}

static	t_pfargs	init_pfargs(char *value, char type, int index)
{
	t_pfargs	pfargs;

	pfargs.value = value;
	pfargs.type = type;
	pfargs.index = index;
	pfargs.len = ft_strlen(pfargs.value);
	return (pfargs);
}

int					count_printf_args(const char *fm)
{
	int			j;
	int			p;
	char		in;
	t_pfargs	pfargs;

	j = 0;
	p = 0;
	while (fm[j])
	{
		if ((p = is_printf_arg(&(fm[j]), &in)) > 0 && (in == 'c' || in == '%'))
		{
			pfargs = init_pfargs(ft_strsub(fm, j, p + 1),
			((in == 'c') ? fm[j + p] : '%'), j);
			if (mult_flag_arg(pfargs.value) && del_gpfargs(&g_pfargs))
				return (0);
			ft_lstadd(&g_pfargs, ft_lstnew((&pfargs), sizeof(pfargs)));
			j = j + p + 1;
		}
		else if (p == -1 && del_gpfargs(&g_pfargs))
			return (0);
		else if (in == 'l')
			j++;
	}
	ft_lstreverse(&g_pfargs);
	return (1);
}
