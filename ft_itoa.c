/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:52:25 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 20:09:47 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	ft_ct(int n)
{
	int		ct;

	ct = 0;
	while (n)
	{
		n = n / 10;
		ct++;
	}
	return (ct);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		ct;

	if (!(ct = (n < 0) ? ft_ct(n) + 1 : ft_ct(n)))
		return (ft_strdup("0"));
	i = 1;
	if (!(str = ft_strnew(ct)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		str[ct - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[ct] = '\0';
	return (str);
}
