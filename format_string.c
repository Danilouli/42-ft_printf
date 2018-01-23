/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:57:17 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 15:59:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char		*format_string_helper(char *flags, char *str,
		size_t width, size_t len)
{
	size_t	i;
	char	*ret;

	i = -1;
	if (!(ret = ft_strnew(width)))
		return (0);
	if (ft_strchr(flags, '-'))
	{
		while (str[++i])
			ret[i] = str[i];
		while (i++ < width)
			ret[i - 1] = ' ';
	}
	else
	{
		while (++i < (width - len))
			ret[i] = ' ';
		while (i++ < width)
			ret[i - 1] = str[i - 1 - (width - len)];
	}
	ret[i - 1] = 0;
	return (ret);
}

char			*format_string(char *form, char *str)
{
	char	*ret;
	char	*flags;
	size_t	width;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	flags = get_flags(form);
	width = get_width(form);
	i = 0;
	if (width <= ft_strlen(str))
		return (ft_strdup(str));
	else
		ret = format_string_helper(flags, str, width, len);
	return (ret);
}

static wchar_t	*format_wstring_helper(char *flags, wchar_t *wstr,
		size_t width, size_t len)
{
	size_t	i;
	wchar_t	*ret;

	i = -1;
	if (!(ret = ft_wstrnew(width)))
		return (0);
	if (ft_strchr(flags, '-'))
	{
		while (wstr[++i])
			ret[i] = wstr[i];
		while (i++ < width)
			ret[i - 1] = ' ';
	}
	else
	{
		while (++i < (width - len))
			ret[i] = ' ';
		while (i++ < width)
			ret[i - 1] = wstr[i - 1 - (width - len)];
	}
	ret[i - 1] = 0;
	return (ret);
}

wchar_t			*format_wstring(char *form, wchar_t *wstr)
{
	wchar_t	*ret;
	char	*flags;
	size_t	width;
	size_t	i;
	size_t	len;

	len = ft_wstrlen(wstr);
	flags = get_flags(form);
	width = get_width(form);
	i = 0;
	if (width <= len)
		return (ft_wstrdup(wstr));
	else
		ret = format_wstring_helper(flags, wstr, width, len);
	return (ret);
}
