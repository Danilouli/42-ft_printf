/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:21:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/26 15:30:27 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*helper_ws_flag(char *snum, int len, int *lenk)
{
	char *formatted;

	if (!(formatted = ft_strnew(len)))
		return (0);
	formatted[0] = ' ';
	formatted = ft_strcat(formatted, snum);
	*lenk = ft_strlen(formatted);
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
	long long		val;
	int		i;
	char	*fg;

	fg = get_flags(form);
	ct = 0;
	i = 0;
	// printf("FLAGS:%s, %lld, SNUM %s\n",fg,ft_atoi(snum),snum);
	if (!(r = ft_strnew(len)))
		return (0);
	if (!ft_strchr(form, 'u') && !ft_strchr(form, 'U') && ft_strchr(fg, '+') && (val = ft_atoi(snum)) >= 0 && ft_strchr(fg, '0')
		&& get_prec(form) < 2 && ct++ >= 0 && nl-- >= 0)
		r[0] = '+';
	// printf("INFO:%d\n",(val = ft_atoi(snum)) < 0 && (ft_strchr(fg, '0') || ft_strchr(fg, '.')));
	if (!ft_strchr(form, 'u') && !ft_strchr(form, 'U') && (val = ft_atoi(snum)) < 0 && ft_strchr(fg, '0') && (get_prec(form) < 2) && ct++ >= 0 && nl-- >= 0 && i++ >= 0)
		r[0] = '-';
	while (ct < len - nl)
	{
		r[ct] = (ft_strchr(fg, '0') && get_prec(form) < 2 && !(ft_strchr(fg, ' ') && !ct)) ? '0' : ' ';
		ct++;
	}
	while (ct < len)
	{
		if (!ft_strchr(form, 'u') && !ft_strchr(form, 'U') && (ct == len - nl) && (r[0] != '+') && ft_strchr(fg, '+') && val >= 0)
			r[ct++] = '+';
		else
			r[ct++] = snum[i++];
	}
	r[ct] = 0;
	return (r);
}

static char* helper_sharp_flag(char *form, char *snum, int len, int nl)
{
	char	*r;
	int		ct;
	int		i;
	char	*fg;

	fg = get_flags(form);
	ct = 0;
	i = 0;
	if (*snum == 0)
		return (snum);
	if (!(r = ft_strnew(len)))
		return (0);
	if (ft_strchr(fg, '0') && (i++ >=0) && (ct++ >= 0) && (nl-- >= 0))
	{
		r[0] = '0';
		if (!deg_is_octal_conv(form) && ct++ >= 0 && nl-- >= 0 && i++ >= 0)
		{
			r[1] = form[ft_strlen(form) - 1];
			// ct++;
			// nl--;
			// i++;
		}
	}
	while (ct < len - nl)
		r[ct++] = (ft_strchr(fg, '0') && get_prec(form) < 2) ? '0' : ' ';
	while (ct < len)
	{
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
	numlen = ft_strlen(snum) + (ft_strchr(flags, '+') && ft_atoi(snum) >= 0 && get_base(form) == 10);
	len = (width > numlen) ? width : numlen;
	ret = snum;
	if (width != len && deg_only_space(flags) && ft_atoi(snum) >= 0 && !ft_strchr(form, 'u') && !ft_strchr(form, 'U'))
	{
		return (snum = helper_ws_flag(snum, len, lenk));
	}
	if (ft_strchr(flags, '-'))
		ret = helper_minus_flag(form, snum, len, numlen);
	else if (ft_strchr(flags, '#') && !(ft_strequ(snum,"0") && (ft_strchr(form, 'o') || ft_strchr(form, 'O')) && ft_strchr(flags, '0')))
		ret = helper_sharp_flag(form, snum, len, numlen);
	else if (!deg_only_space(flags) || width)
	{
		// printf("SNUM %s\n",snum);
		ret = helper_others_flag(form, snum, len, numlen);
		// printf("RET %s\n",ret);
	}
	*lenk = ft_strlen(ret);
	return (ret);
}
