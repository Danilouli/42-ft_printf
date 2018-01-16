/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:21:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/16 16:42:41 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char *helper_ws_flag(char *snum, int len)
{
	char *formatted;

	if (!(formatted = ft_strnew(len)))
		return (0);
	formatted[0] = ' ';
	formatted = ft_strcat(formatted,snum);
	return (formatted);
}

static char *helper_minus_flag(char *form, char *snum, int len, int numlen)
{
	char *formatted;
	int ct;
	int val;
	int i;
	char *flags;

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

static char *helper_others_flag(char *form, char *snum, int len, int numlen)
{
	char *formatted;
	int ct;
	int val;
	int i;
	char *flags;

	flags = get_flags(form);
	ct = 0;
	i = 0;
	val = ft_atoi(snum);
	if (!(formatted = ft_strnew(len)))
		return (0);
	if (ft_strchr(flags, '+') && val >= 0 && ft_strchr(flags, '0') && !get_prec(form) && ct++ >= 0 && numlen-- >= 0)
		formatted[0] = '+';
	while (ct < len - numlen)
		formatted[ct++] = (ft_strchr(flags, '0') && !get_prec(form)) ? '0' : ' ';
	while (ct < len)
	{
		if ((ct == len - numlen) && (formatted[0] != '+') && ft_strchr(flags, '+') && val >= 0)
			formatted[ct++] = '+';
		else
			formatted[ct++] = snum[i++];
	}
	formatted[ct] = 0;
	return (formatted);
}

char *format_numeric(char *form, char *snum, int width, int *lenk)
{
	int numlen;
	int len;
	char *ret;
	char *flags;

	flags = get_flags(form);
	numlen = ft_strlen(snum) + (ft_strchr(flags, '+') && ft_atoi(snum) >= 0);
	len = (width > numlen) ? width : numlen;
	if (width == 0 && ft_strchr(flags, ' '))
		ret = helper_ws_flag(snum, len);
	if (ft_strchr(flags, '-'))
		ret = helper_minus_flag(form, snum, len, numlen);
	else
		ret = helper_others_flag(form, snum, len, numlen);
	*lenk = ft_strlen(ret);
	return (ret);
}

void cast_numeric(long long *val, char *flags)
{
	if(flags) {
		if (ft_strstr(flags, "hh"))
			*val = (char)(*val);
		else if (ft_strchr(flags, 'h'))
			*val = (short)(*val);
		else if (ft_strstr(flags, "ll"))
			*val = (long long)(*val);
		else if (ft_strchr(flags, 'l'))
			*val = (long)(*val);
		else if (ft_strchr(flags, 'j'))
			*val = (intmax_t)(*val);
		else if (ft_strchr(flags, 'z'))
			*val = (size_t)(*val);
		else
			*val = (int)(*val);
	}
	else
		*val = (int)(*val);
	return;
}
