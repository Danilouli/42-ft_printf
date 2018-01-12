/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:23:19 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/11 18:48:24 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

t_conv g_convertors[] =
{
	{'d', &intconv},
	{'c', &charconv},
	{'s', &strconv}
};

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

int ft_fprintf(int fd, const char *format, ...)
{
	(void)fd;
	char *keep;
	char *res;
	int formlen;
	int ct = -1;
	va_list(ap);
	va_start(ap, format);
	count_printf_args(format);
	formlen = 0;
	while (*format)
	{
		if (is_printf_arg(format))
		{
			if(g_pfargs)
			{
				keep = PFARGS(value);
				while (ct++ < 3)
				{
					if (PFARGS(type) == g_convertors[ct].sign)
					{
						res = g_convertors[ct].convertor(keep,ap);
					}
				}
				ct = -1;
				ft_putstr(res);
				formlen += (PFARGS(len) - 1);
				format += PFARGS(len);
				g_pfargs = g_pfargs->next;
			}
		}
		else
		{
			ft_putchar(*format);
			formlen++;
			format++;
		}
	}
	return (formlen);
}

int	main(int argc, char **argv)
{
	int ret;
	if (argc < 2)
		return (0);
	ret = ft_fprintf(0, argv[1], 5, 'E', 8);
	ft_putchar('\n');
	ft_putnbr(ret);
	return(0);
}
