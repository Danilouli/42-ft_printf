/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:13:39 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/14 21:52:42 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	printf("te %s st\n", "dq");
	printf("te %hd st\n", 700000);
	printf("te %03d st\n", 7);
	printf("te %-2d st\n", 71);
	printf("te %.2d st\n", 7);
	printf("te %.2d st\n", 71);
}
