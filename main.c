/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:51:16 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 14:11:39 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	char *uil;
	// char op = 9;
	// char *rut;
	// (void)argv;
	//char allowed_flags[5] = "+-0 z";
	if (argc < 2)
		return (0);
	uil = ft_itoa_base(161, 16, 0);
	// printf("===>%s\n",uil);
	ft_printf("a %#o %s %ls % % l\n", &uil, "ehe", L"êèœ");
	ft_printf("a %#o %s %ls % % l\n", 15, "ehe", L"êèœ");
	ft_fprintf(0, argv[1], &uil, "ehe", L"êèœ");
	// rut = add_prec_to_snum("","7");
	ft_putchar('\n');
	return(0);
}
