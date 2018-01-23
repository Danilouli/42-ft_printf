/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:29:22 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 17:15:01 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				is_printf_flag(char c)
{
	return (ft_strchr("#0-+ .hljzvV123456789", c) != 0);
}

int				is_printf_conversion(char c)
{
	return (ft_strchr("sSpdDioOuUxXbBcC", c) != 0);
}

int				is_printf_arg(const char *format, char *info)
{
	int		c;
	char	*str;

	str = (char*)format;
	c = 0;
	*info = 'l';
	if (*str != '%')
		return (0);
	str++;
	while (*str && ++c)
	{
		if (!is_printf_flag(*str) && !is_printf_conversion(*str)
			&& *str != '%' && (*info = 'e'))
			return (-1);
		else if (*str == '%' && (*info = '%'))
			return (c);
		else if (is_printf_conversion(*str) && (*info = 'c'))
			return (c);
		str++;
	}
	return (-1);
}

static t_pfargs	init_pfargs(char *value, char type, int index)
{
	t_pfargs	pfargs;

	pfargs.value = value;
	pfargs.type = type;
	pfargs.index = index;
	pfargs.len = ft_strlen(pfargs.value);
	return (pfargs);
}

int				count_printf_args(const char *form)
{
	int			j;
	int			p;
	char		infos;
	t_pfargs	pfargs;

	j = 0;
	p = 0;
	while (form[j])
	{
		p = is_printf_arg(&(form[j]), &infos);
		if (p > 0 && (infos == 'c' || infos == '%'))
		{
			pfargs = init_pfargs(ft_strsub(form, j, p + 1),
				((infos == 'c') ? form[j + p] : '%'), j);
			ft_lstadd(&g_pfargs, ft_lstnew((&pfargs), sizeof(pfargs)));
			j = j + p + 1;
		}
		else if (p == -1 && !(g_pfargs = 0))
			return (0);
		else if (infos == 'l')
			j++;
	}
	ft_lstreverse(&g_pfargs);
	return (1);
}
