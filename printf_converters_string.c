/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 14:01:50 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ft_printf.h"
	#include <stdio.h>

	wchar_t *charconv(char* form, va_list ap, int *len) {
		char *ret;
		char *flags;
		int width;

		flags = get_flags(form);
		width = get_width(form);
		if (ft_strchr(form,'l'))
			return (wcharconv(form, ap, len));
		// ret = ft_itos(va_arg(ap, int));
		ret = format_string(form, ft_itos(va_arg(ap, int)));
		*len = ft_max(ft_strlen(ret), width);
		return ((wchar_t*)ret);
	}

	wchar_t *strconv(char *form, va_list ap, int *len)
	{
		char *ret;
		char *flags;
		int width;

		flags = get_flags(form);
		width = get_width(form);
		if (ft_strchr(form,'l'))
			return (wstrconv(form, ap, len));
		// ret = ft_strdup(va_arg(ap, char*));
		ret = format_string(form, va_arg(ap, char*));
		*len = ft_max(ft_strlen(ret), width);
		return ((wchar_t*)ret);
	}

	wchar_t *wcharconv(char *form, va_list ap, int *len)
	{
		wchar_t *ret;
		char *flags;
		int width;

		flags = get_flags(form);
		width = get_width(form);
		ret = format_wstring(form, ft_itows(va_arg(ap, int)));
		*len = ft_max(ft_wstrlen(ret),width);
		return (ret);
	}

	wchar_t *wstrconv(char *form, va_list ap, int *len)
	{
		wchar_t *ret;
		char *flags;
		int width;

		flags = get_flags(form);
		width = get_width(form);
		ret = format_wstring(form, va_arg(ap, wchar_t*));
		*len = ft_max(ft_wstrlen(ret),width);
		return (ret);
	}
