/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:23:19 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 17:33:26 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

t_conv convertors[] =
{
	{'d', &numconv},
	{'i', &numconv},
	{'u', &numconv},
	{'U', &numconv},
	{'D', &numconv},
	{'x', &numconv},
	{'X', &numconv},
	{'o', &numconv},
	{'O', &numconv},
	{'b', &numconv},
	{'B', &numconv},
	{'p', &numconv},
	{'c', &charconv},
	{'C', &wcharconv},
	{'s', &strconv},
	{'S', &wstrconv},
	{'%', &perconv}
};

int ft_fprintf(int fd, const char *format, ...)
{
	(void)fd;
	wchar_t *res;
	int lenk = 0;
	int ct = 0;
	int i = -1;
	int formlen = 0;
	va_list(ap);
	va_start(ap, format);
	if(!count_printf_args(format))
		return (-1);
	while (format[ct])
	{
		if (g_pfargs && ct == PFARGS(index))
		{
			while (++i < 17)
			{
				if (PFARGS(type) == convertors[i].sign)
				{
					res = convertors[i].convertor(PFARGS(value), ap, &lenk);
					(PFARGS(type) == 'S' || PFARGS(type) == 'C' ||
					((PFARGS(type) == 's' || PFARGS(type) == 'c')
					&& ft_strchr(PFARGS(value),'l'))) ?
					ft_putwstr(res) : ft_putstr((char*)res);
					break;
				}
			}
			i = -1;
			formlen += lenk;
			ct += PFARGS(len);
			g_pfargs = g_pfargs->next;
		}
		else
		{
			ft_putchar(format[ct]);
			formlen++;
			ct++;
		}
	}
	va_end(ap);
	return (formlen);
}

int	main(int argc, char **argv)
{
	int ret;
	ret = 0;
	char *uil;
	wchar_t *tutu;
	// char op = 9;
	// char *rut;
	// (void)argv;
	//char allowed_flags[5] = "+-0 z";
	if (argc < 2)
		return (0);
	uil = ft_itoa_base(161, 16, 0);
	// printf("===>%s\n",uil);
	ret = ft_fprintf(0, argv[1], &uil);
	// rut = add_prec_to_snum("","7");
	ft_putchar('\n');
	printf("YOYOYOYO===>%p\n",&uil);
	ft_putstr("ret->");
	if(ret)
		ft_putnbr(ret);
	ft_putchar('>');
	ft_putchar('\n');
	ft_putwchar(L'č');
	ft_putwchar(L'\n');
	ft_putwstr(L"ač");
	tutu = ft_itows(233);
	ft_putwstr(tutu);
	return(0);
}
