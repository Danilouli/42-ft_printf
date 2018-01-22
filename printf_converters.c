/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 17:35:42 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ft_printf.h"
	#include <stdio.h>

	int no_unallowed_flag(char allowed_flags[], char *form)
	{
		while (*form)
		{
			if (!(*(form + 1)))
				break;
			if (*form != '%' && !ft_strchr(allowed_flags, *form) && !ft_isdigit(*form))
				return (0);
			form++;
		}
		return (1);
	}

	int get_width(char *form)
	{
		while(*form && !(ft_isdigit(*form) && *form != '0')
			&& *form != 'v' && *form != 'V')
			form++;
		if (ft_isdigit(*form) && *form != '0')
			return (ft_atoi(form));
		return (0);
	}

	int get_prec(char *form)
	{
		while (*form && *form != '.')
			form++;
		if (*form == '.')
			return ((ft_atoi(form + 1) == 0) ? 1 : ft_atoi(form + 1));
		return (0);
	}

	char *add_prec_to_snum(char *form, char *snum)
	{
		int prec;
		size_t i;
		size_t zer_to_add;
		char *ret;

		i = 0;
		if ((prec = get_prec(form)) < 2)
			return (snum);
		zer_to_add = prec - ft_strlen(snum);
		if(!(ret = ft_strnew(zer_to_add + ft_strlen(snum))))
			return (0);
		while (i < zer_to_add)
		{
			ret[i] = '0';
			i++;
		}
		while (i < (zer_to_add + ft_strlen(snum)))
		{
			ret[i] = snum[i - zer_to_add];
			i++;
		}
		ret[i] = 0;
		return (ret);
	}

	char *get_flags(char *form)
	{
		int ct;

		ct = 0;
		form++;
		while (form[ct])
		{
			if(!form[ct + 1])
				break;
			if(ft_isdigit(form[ct]) && form[ct] != '0')
				break;
			ct++;
		}
		if (ct)
			return (ft_strsub(form, 0, ct));
		return ("");
	}

	int get_base(char *form)
	{
		while (*form && *form != 'v' && *form != 'V' && *form != 'o' && *form != 'O'
			&& *form != 'x' && *form != 'X' && *form != 'b' && *form != 'B' && *form != 'p')
			form++;
		if (*form == 'b' || *form == 'B')
				return (2);
		if (*form == 'o' || *form == 'O')
			return (8);
		if (*form == 'x' || *form == 'X')
			return (16);
		if (*form == 'p')
			return (16);
		if (*form == 'v' || *form == 'V')
		{
			if(!ft_isdigit(*(form + 1)))
				return (10);
			else
				return ((ft_atoi(form + 1) == 0 || ft_atoi(form + 1) == 1) ? 10 : ft_atoi(form + 1));
		}
		return (10);
	}

	wchar_t *perconv(char* form, va_list ap, int *len) {
		(void)ap;
		(void)form;

		*len = 1;
		return ((wchar_t*)"%");
	}

	wchar_t *numconv(char* form, va_list ap, int *len) {
		char *snum;
		char allowed_flags[] = "#+-0. hljzv";
		char *flags;
		int width;
		long long val;

		val = va_arg(ap, long long);
		if (!no_unallowed_flag(allowed_flags, form))
			return (0);
		flags = get_flags(form);
		width = get_width(form);
		cast_numeric(&val, flags, form);
		if (!(snum = add_prec_to_snum(form ,ft_itoa_base(val, get_base(form), ft_isupper(form[ft_strlen(form) - 1])))))
			return (0);
		if (ft_strchr(flags, '#'))
		{
			if (get_base(form) == 2)
				snum = ft_strjoin("0b",snum);
			else if (get_base(form) == 8)
				snum = ft_strjoin("0o",snum);
			else if (get_base(form) == 16)
				snum = ft_strjoin("0x",snum);
		}
		return ((wchar_t*)format_numeric(form, snum, width, len));
	}

	char *format_string(char *form, char *str)
	{
		char *ret;
		char *flags;
		size_t width;
		size_t i;
		size_t len;

		len = ft_strlen(str);
		flags = get_flags(form);
		width = get_width(form);
		i = 0;
		if(width <= ft_strlen(str))
			return (ft_strdup(str));
		else
		{
			if (!(ret = ft_strnew(width)))
				return (0);
			if (ft_strchr(flags, '-'))
			{
				while (str[i])
				{
					ret[i] = str[i];
					i++;
				}
				while (i < width)
				{
					ret[i] = ' ';
					i++;
				}
			}
			else
			{
				while (i < (width - len))
				{
					ret[i] = ' ';
					i++;
				}
				while (i < width)
				{
					ret[i] = str[i - (width - len)];
					i++;
				}
			}
		}
		ret[i] = 0;
		return (ret);
	}

	wchar_t *format_wstring(char *form, wchar_t *str)
	{
		wchar_t *ret;
		char *flags;
		size_t width;
		size_t i;
		size_t len;

		len = ft_wstrlen(str);
		flags = get_flags(form);
		width = get_width(form);
		i = 0;
		if(width <= len)
			return (ft_wstrdup(str));
		else
		{
			if (!(ret = ft_wstrnew(width)))
				return (0);
			if (ft_strchr(flags, '-'))
			{
				while (str[i])
				{
					ret[i] = str[i];
					i++;
				}
				while (i < width)
				{
					ret[i] = ' ';
					i++;
				}
			}
			else
			{
				while (i < (width - len))
				{
					ret[i] = ' ';
					i++;
				}
				while (i < width)
				{
					ret[i] = str[i - (width - len)];
					i++;
				}
			}
		}
		ret[i] = 0;
		return (ret);
	}

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
