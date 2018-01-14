/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 02:48:26 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/14 20:56:49 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long				ft_atoi(char const *s)
{
	int			sign;
	long long	res;
	size_t		i;

	res = 0;
	sign = 0;
	i = 0;
	while (*s == '\n' || *s == '\t' || *s == '\r' || *s == '\v' || *s == '\f'
		|| *s == ' ')
		s++;
	if (!(sign = (*s == '-' || *s == '+') ? (44 - *s) : 0) && !ft_isdigit(*s))
		return (0);
	s = (sign) ? (s + 1) : s;
	sign = (!sign) ? 1 : sign;
	while (*s == '0')
		s++;
	while (ft_isdigit(*s))
	{
		res = 10 * res + (*s - '0');
		s++;
		if (i++ > 19 || res > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
	}
	return (res * sign);
}
