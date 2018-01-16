/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:41:52 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/16 18:59:46 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>


char	*ft_create_base(int b)
{
	char	*base;
	int		i;

	i = 0;
	if (!(base = ft_strnew(b)))
	return (0);
	while (i < b)
	{
		base[i] = (b > 10 && i >= 10) ? ('A' + i - 10) : (i + '0');
		i++;
	}
	base[i] = 0;
	return (base);
}
