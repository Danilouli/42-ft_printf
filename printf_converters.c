/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/16 19:17:28 by dsaadia          ###   ########.fr       */
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
		while(*form && !(ft_isdigit(*form) && *form != '0') && *form != 'b' && *form != 'B')
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
		while (*form && *form != 'b' && *form != 'B' && *form != 'o' && *form != 'O'
			&& *form != 'x' && *form != 'X')
			form++;
		if (*form == 'o' || *form == 'O')
			return (8);
		if (*form == 'x' || *form == 'X')
			return (16);
		if (*form == 'b' || *form == 'B')
		{
			if(!ft_isdigit(*(form + 1)) || *(form + 1) == '0')
				return (10);
			else
				return (ft_atoi(form + 1));
		}
		return (10);
	}

	char *perconv(char* form, va_list ap, int *len) {
		(void)ap;
		(void)form;

		*len = 1;
		return ("%");
	}

	char *numconv(char* form, va_list ap, int *len) {
		char *snum;
		char allowed_flags[] = "+-0. hljzb";
		char *flags;
		int width;
		long long val;

		val = va_arg(ap, long long);
		if (!no_unallowed_flag(allowed_flags, form))
			return (0);
		flags = get_flags(form);
		width = get_width(form);
		cast_numeric(&val, flags);
		if (!(snum = add_prec_to_snum(form ,ft_itoa_base(val, get_base(form)))))
			return (0);
		return (format_numeric(form, snum, width, len));
	}

	char *charconv(char* form, va_list ap, int *len) {
		char *ret;

		(void)form;
		ret = ft_itos(va_arg(ap, int));
		*len = ft_strlen(ret);
		return (ret);
	}

	char *strconv(char *form, va_list ap, int *len)
	{
		char *ret;

		(void)form;
		ret = ft_strdup(va_arg(ap, char*));
		*len = ft_strlen(ret);
		return (ret);
	}
