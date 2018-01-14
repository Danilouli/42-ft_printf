/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/14 19:14:33 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ft_printf.h"
	#include "stdio.h"


	int no_unallowed_flag(char allowed_flags[5], char *form)
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
		while(*form && !(ft_isdigit(*form) && *form != '0'))
			form++;
		if (ft_isdigit(*form) && *form != '0')
			return (ft_atoi(form));
		return (0);
	}

	char* get_flags(char *form)
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
		return (0);
	}

	char *perconv(char* form, va_list ap, int *len) {
		(void)ap;
		(void)form;

		*len = 1;
		return ("%");
	}

	char *format_numeric(char *flags, char *snum, int width, long long int val)
	{
		char *formatted;
		int ct;
		int numlen;
		int len;
		int i;

		i = 0;
		numlen = ft_strlen(snum) + (ft_strchr(flags, '+') && val >= 0);
		len = (width > numlen) ? width : numlen;
		ct = 0;
		if (!(formatted = ft_strnew(len)))
			return (0);
		if (width == 0 && ft_strchr(flags, ' '))
		{
			formatted[0] = ' ';
			formatted = ft_strcat(formatted,snum);
			return (formatted);
		}
		if (ft_strchr(flags, '-'))
		{
			if (ft_strchr(flags, '+') && val >= 0 && ct++ >= 0)
			{
				formatted[0] = '+';
				// ct++;
			}
			while (ct < numlen)
			{
				formatted[ct++] = snum[i++];
				// ct++;
			}
			while (ct < len)
			{
				formatted[ct++] = ' ';
				// ct++;
			}
			// formatted[ct] = 0;
		}
		else
		{
			if (ft_strchr(flags, '+') && val >= 0 && ft_strchr(flags, '0') && ct++ >= 0 && numlen-- >= 0)
			{
				formatted[0] = '+';
				// ct++;
				// numlen--;
			}
			while (ct < len - numlen)
			{
				formatted[ct++] = (ft_strchr(flags, '0')) ? '0' : ' ';
				printf("-->%s\n",formatted);
				// ct++;
			}
			printf("ct%d\n",ct);
			while (ct < len)
			{
				formatted[ct++] = (ft_strchr(flags, '+') && !ft_strchr(flags, '0') && ct == len - numlen) ? '+' : snum[i++];
				printf("->%s\n",formatted);
				// ct++;
			}
			// formatted[ct] = 0;
		}
		formatted[ct] = 0;
		return (formatted);
	}

	char *intconv(char* form, va_list ap, int *len) {
		char *ret;
		char allowed_flags[5] = "+-0 z";
		char *flags;
		int val;
		int width;

		val = va_arg(ap, int);
		if (!no_unallowed_flag(allowed_flags, form))
			return (0);
		flags = get_flags(form);
		width = get_width(form);
		ret = ft_itoa(val);
		*len = ft_strlen(ret);
		return (ret);
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
