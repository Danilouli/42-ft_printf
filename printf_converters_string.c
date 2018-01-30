/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:42 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*charconv(char *form, va_list ap, int *len)
{
	char	*ret;
	char	*flags;
	int		width;
	int		val;
	char	*k;

	width = get_width(form);
	if (ft_strchr(form, 'l'))
		return (wcharconv(form, ap, len));
	flags = get_flags(form);
	if ((val = va_arg(ap, int)) == 0)
	{
		while (!ft_strchr(flags, '.') && width-- > 1 && (*len)++ >= 0)
			ft_putchar(' ');
		ft_putchar(val);
		(*len)++;
		free(flags);
		return (ft_wstrdup((wchar_t*)("\0")));
	}
	k = ft_itos(val);
	ret = format_string(form, k);
	*len = ft_max(ft_strlen(ret), width);
	free(flags);
	free(k);
	return ((wchar_t*)ret);
}

wchar_t	*strconv(char *form, va_list ap, int *len)
{
	char	*ret;
	int		width;
	char	*val;

	width = get_width(form);
	if (ft_strchr(form, 'l'))
		return (wstrconv(form, ap, len));
	if (!(val = va_arg(ap, char*)))
		val = "(null)";
	ret = format_string(form, val);
	*len = ft_max(ft_strlen(ret), width);
	return ((wchar_t*)ret);
}

wchar_t	*wcharconv(char *form, va_list ap, int *len)
{
	wchar_t	*ret;
	char	*flags;
	int		width;
	int		val;
	wchar_t	*k;

	flags = get_flags(form);
	width = get_width(form);
	if ((val = va_arg(ap, int)) == 0)
	{
		while (!ft_strchr(flags, '.') && width-- > 1 && (*len)++ >= 0)
			ft_putchar(' ');
		ft_putchar(val);
		(*len)++;
		free(flags);
		return (ft_wstrdup((wchar_t*)("\0")));
	}
	k = ft_itows(val);
	ret = format_wstring(form, k);
	*len = ft_max(ft_wstrlen(ret), width);
	free(flags);
	free(k);
	return (ret);
}

wchar_t	*wstrconv(char *form, va_list ap, int *len)
{
	wchar_t	*ret;
	int		width;
	wchar_t *val;

	width = get_width(form);
	if (!(val = va_arg(ap, wchar_t*)))
		val = L"(null)";
	ret = format_wstring(form, val);
	*len = ft_max(ft_wstrlen(ret), width);
	return (ret);
}
