/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:13:39 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/16 19:19:24 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	wchar_t a = L'é';
	//int u[] = {2,4,5};
	// wprintf(L"%c\n", a);
	// write(1, &a, 4);
	printf("a %x l\n", 161);
	// printf("a %03d l\n", 7);
	// printf("a %-2d l\n", 71);
	// printf("a %.2d l\n", 7);
	// printf("a %.2d l\n", 71);
}
