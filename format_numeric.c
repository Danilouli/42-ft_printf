/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:21:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 15:15:43 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*helper_ws_flag(char *snum, int len)
{
	char *formatted;

	if (!(formatted = ft_strnew(len)))
		return (0);
	formatted[0] = ' ';
	formatted = ft_strcat(formatted, snum);
	return (formatted);
}

static char	*helper_minus_flag(char *form, char *snum, int len, int numlen)
{
	char	*formatted;
	int		ct;
	int		val;
	int		i;
	char	*flags;

	flags = get_flags(form);
	ct = 0;
	i = 0;
	val = ft_atoi(snum);
	if (!(formatted = ft_strnew(len)))
		return (0);
	if (ft_strchr(flags, '+') && val >= 0 && ct++ >= 0)
		formatted[0] = '+';
	while (ct < numlen)
		formatted[ct++] = snum[i++];
	while (ct < len)
		formatted[ct++] = ' ';
	formatted[ct] = 0;
	return (formatted);
}

static char	*helper_others_flag(char *form, char *snum, int len, int nl)
{
	char	*r;
	int		ct;
	int		val;
	int		i;
	char	*fg;

	fg = get_flags(form);
	ct = 0;
	i = 0;
	if (!(r = ft_strnew(len)))
		return (0);
	if (ft_strchr(fg, '+') && (val = ft_atoi(snum)) >= 0 && ft_strchr(fg, '0')
		&& !get_prec(form) && ct++ >= 0 && nl-- >= 0)
		r[0] = '+';
	while (ct < len - nl)
		r[ct++] = (ft_strchr(fg, '0') && !get_prec(form)) ? '0' : ' ';
	while (ct < len)
	{
		if ((ct == len - nl) && (r[0] != '+') && ft_strchr(fg, '+') && val >= 0)
			r[ct++] = '+';
		else
			r[ct++] = snum[i++];
	}
	r[ct] = 0;
	return (r);
}

char		*format_numeric(char *form, char *snum, int width, int *lenk)
{
	int		numlen;
	int		len;
	char	*ret;
	char	*flags;

	flags = get_flags(form);
	numlen = ft_strlen(snum) + (ft_strchr(flags, '+') && ft_atoi(snum) >= 0);
	len = (width > numlen) ? width : numlen;
	if (width == 0 && ft_strchr(flags, ' '))
		snum = helper_ws_flag(snum, len);
	if (ft_strchr(flags, '-'))
		ret = helper_minus_flag(form, snum, len, numlen);
	else
		ret = helper_others_flag(form, snum, len, numlen);
	*lenk = ft_strlen(ret);
	return (ret);
}

void		cast_numeric(long long *val, char *form)
{
	if (form)
	{
		if (ft_strstr(form, "hh"))
			*val = (char)(*val);
		else if (ft_strchr(form, 'h'))
			*val = (short)(*val);
		else if (ft_strstr(form, "ll") || ft_strchr(form, 'p'))
			*val = (long long)(*val);
		else if (ft_strchr(form, 'l'))
			*val = (long)(*val);
		else if (ft_strchr(form, 'j'))
			*val = (intmax_t)(*val);
		else if (ft_strchr(form, 'z'))
			*val = (size_t)(*val);
		else
			*val = (int)(*val);
	}
	else
		*val = (int)(*val);
	return ;
}
