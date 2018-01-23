/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:57:17 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 13:57:45 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
