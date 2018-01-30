/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:18:27 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 17:47:38 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	gmi(unsigned long long nb, int base, int sign)
{
	long long		i;

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

static void			positivize_num(unsigned long long *nb, char *form,
		long long value, int base)
{
	if (base == 10)
		*nb = (value < 0) ? -value : value;
	else if (form)
	{
		if (ft_strstr(form, "hh"))
			*nb = (value < 0) ? (unsigned char)value : value;
		else if (ft_strchr(form, 'h'))
			*nb = (value < 0) ? (unsigned short)value : value;
		else if (ft_strstr(form, "ll") || ft_strchr(form, 'p'))
			*nb = (value < 0) ? (unsigned long long)value : value;
		else if (ft_strchr(form, 'l'))
			*nb = (value < 0) ? (unsigned long)value : value;
		else if (ft_strchr(form, 'j'))
			*nb = (value < 0) ? (intmax_t)value : value;
		else if (ft_strchr(form, 'z'))
			*nb = (value < 0) ? (size_t)value : value;
		else
			*nb = (value < 0) ? (unsigned int)value : value;
	}
	else
		*nb = (value < 0) ? (unsigned int)value : value;
	return ;
}

char				*pf_itoa_base(long long value, int base, char *fm)
{
	char				*b_string;
	char				*ret;
	unsigned long long	nb;
	long long			i;

	i = 0;
	positivize_num(&nb, fm, value, base);
	if (!value)
		return (ft_strdup("0"));
	if (value == -9223372036854775807 && base == 10)
		return (ft_strdup("-9223372036854775807"));
	if (!(ret = (char*)malloc(gmi(nb, base, value < 0) + 1))
	|| !(b_string = ft_create_base(base, ft_isupper(LCHR(fm)))))
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
	free(b_string);
	return (ret);
}

char				*pf_uitoa_base(unsigned long long value, int base, char *fm)
{
	char				*b_string;
	char				*ret;
	unsigned long long	nb;
	long long			i;

	i = 0;
	nb = value;
	if (!value)
		return (ft_strdup("0"));
	if (!(ret = (char*)malloc(gmi(nb, base, 0) + 1)))
		return (0);
	if (!(b_string = ft_create_base(base, ft_isupper(LCHR(fm)))))
		return (0);
	while (nb > 0)
	{
		ret[i++] = b_string[nb % base];
		nb = nb / base;
	}
	ret[i] = 0;
	ft_astrrev(&ret);
	free(b_string);
	return (ret);
}
