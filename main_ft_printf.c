/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:31:05 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 12:43:43 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	ret = ft_fprintf(0, argv[1], 1598814528);
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
