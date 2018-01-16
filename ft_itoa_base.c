/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:24:00 by exam              #+#    #+#             */
/*   Updated: 2018/01/16 19:00:44 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	gmi(int nb, int base, int sign)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (sign)
		i++;
	while (nb > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char		*ft_itoa_base(long long value, int base)
{
	char	*b_string;
	char	*ret;
	int		nb;
	int		i;

	i = 0;
	nb = (value < 0) ? -value : value;
	if (!value)
		return (ft_strdup("0"));
	if (value == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	if (!(ret = (char*)malloc(gmi(nb, base, value < 0) + 1)))
		return (0);
	if (!(b_string = ft_create_base(base)))
		return (0);
	while (nb > 0)
	{
		ret[i++] = b_string[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		ret[i++] = '-';
	ret[i] = 0;
	ft_astrrev(&ret);
	return (ret);
}
