/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:41:52 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/13 19:23:46 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_create_base(int b)
{
	char	*base;
	int		i;

	i = -1;
	if (0 == (base = (char*)malloc(b + 1)))
		return (0);
	if (b <= 10)
	{
		while (++i < b)
			base[i] = i + '0';
		base[i] = 0;
	}
	if (b > 10)
	{
		while (++i < 10)
			base[i] = i + '0';
		while (++i < b)
			base[i] = 'A' + i - 10;
		base[i] = 0;
	}
	return (base);
}
