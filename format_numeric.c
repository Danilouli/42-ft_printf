/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:21:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:12 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper_ws_flag(char *snum, int len, int *lenk)
{
	char *formatted;

	if (!(formatted = ft_strnew(len)))
		return (0);
	formatted[0] = ' ';
	formatted = ft_strcat(formatted, snum);
	*lenk = ft_strlen(formatted);
	free(snum);
	return (formatted);
}

static char	*helper_minus_flag(char *form, char *snum, int len, int numlen)
{
	char	*formatted;
	int		ct;
	int		val;
	int		i;
	char	*flags;

	ct = 0;
	i = 0;
	val = ft_atoi(snum);
	if (!(formatted = ft_strnew(len)))
		return (0);
	flags = get_flags(form);
	if (ft_strchr(flags, '+') && val >= 0 && ct++ >= 0)
		formatted[0] = '+';
	while (ct < numlen)
		formatted[ct++] = snum[i++];
	while (ct < len)
		formatted[ct++] = ' ';
	formatted[ct] = 0;
	free(flags);
	return (formatted);
}

static char	*helper_others_flag(char *form, char *sn, int len, int nl)
{
	char		*r;
	int			ct;
	long long	val;
	int			i;
	char		*fg;

	ct = 0;
	i = 0;
	if (!(r = ft_strnew(len)))
		return (0);
	fg = get_flags(form);
	if (deg_nf(form, fg, &val, sn) && ct++ >= 0 && nl-- >= 0)
		r[0] = '+';
	if (deg_nf2(form, fg, &val, sn) && ct++ >= 0 && nl-- >= 0 && i++ >= 0)
		r[0] = '-';
	while (ct < len - nl)
		r[ct++] = (ft_strchr(fg, '0') && get_prec(form) < 2
		&& !(ft_strchr(fg, ' ') && !(ct - 1))) ? '0' : ' ';
	while (ct < len)
		r[ct++] = (deg_nf3(form, fg, r, val)
		&& (ct == len - nl)) ? '+' : sn[i++];
	r[ct] = 0;
	free(fg);
	return (r);
}

static char	*helper_sharp_flag(char *form, char *snum, int len, int nl)
{
	char	*r;
	int		ct;
	int		i;
	char	*fg;

	ct = 0;
	i = 0;
	if (*snum == 0)
		return (ft_strdup(snum));
	if (!(r = ft_strnew(len)))
		return (0);
	fg = get_flags(form);
	if (ft_strchr(fg, '0') && (i++ >= 0) && (ct++ >= 0) && (nl-- >= 0))
	{
		r[0] = '0';
		if (!deg_is_octal_conv(form) && ct++ >= 0 && nl-- >= 0 && i++ >= 0)
			r[1] = LCHR(form);
	}
	while (ct < len - nl)
		r[ct++] = (ft_strchr(fg, '0') && get_prec(form) < 2) ? '0' : ' ';
	while (ct < len)
		r[ct++] = snum[i++];
	r[ct] = 0;
	free(fg);
	return (r);
}

char		*format_numeric(char *form, char *snum, int width, int *lenk)
{
	int		numlen;
	int		len;
	char	*ret;
	int		del;
	char	*flags;

	flags = get_flags(form);
	del = 0;
	numlen = deg_nl(form, flags, snum);
	len = (width > numlen) ? width : numlen;
	ret = snum;
	if (width != len && deg_only_space(flags) && ft_atoi(snum) >= 0
	&& !ft_strchr("uU", LCHR(form)) && cool_freer(flags))
		return (helper_ws_flag(snum, len, lenk));
	if (ft_strchr(flags, '-') && (del = 1))
		ret = helper_minus_flag(form, snum, len, numlen);
	else if (ft_strchr(flags, '#') && deg_o_sh(snum, form, flags) && (del = 1))
		ret = helper_sharp_flag(form, snum, len, numlen);
	else if ((!deg_only_space(flags) || width) && (del = 1))
		ret = helper_others_flag(form, snum, len, numlen);
	*lenk = ft_strlen(ret);
	free(flags);
	if (del)
		free(snum);
	return (ret);
}
