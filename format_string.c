/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:57:17 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_prec_str(char *form)
{
	while (*form && *form != '.')
		form++;
	if (*form == '.')
		return (ft_atoi(form + 1));
	return (1);
}

static char		*format_string_helper(char *form, char *str,
		size_t width, size_t len)
{
	size_t		i;
	char		*ret;
	char		*flags;

	i = -1;
	if (!(ret = ft_strnew(width)))
		return (0);
	if (ft_strchr((flags = get_flags(form)), '-'))
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
	free(flags);
	return (ret);
}

char			*format_string(char *form, char *str)
{
	char	*ret;
	size_t	width;
	int		prec;
	size_t	len;
	char	*k;

	ret = ft_strdup(str);
	width = get_width(form);
	if (ft_strchr(form, '.') && !ft_strchr(form, 'c')
		&& ((prec = get_prec_str(form)) < (int)ft_strlen(ret))
		&& form[ft_strlen(form) - 1] != '%')
		ret[prec] = 0;
	if (width <= (len = ft_strlen(ret)))
		return (ret);
	else
	{
		k = ret;
		ret = format_string_helper(form, ret, width, len);
		free(k);
	}
	return (ret);
}

static wchar_t	*format_wstring_helper(char *form, wchar_t *wstr,
		size_t width, size_t len)
{
	size_t	i;
	wchar_t	*ret;

	i = -1;
	if (!(ret = ft_wstrnew(width)))
		return (0);
	if (ft_strchr(form, '-'))
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
	size_t	width;
	int		prec;
	size_t	len;
	wchar_t	*k;

	ret = ft_wstrdup(wstr);
	width = get_width(form);
	if (ft_strchr(form, '.') && !ft_strchr(form, 'C')
		&& !ft_strchr(form, 'c')
		&& ((prec = get_prec_str(form)) < (int)ft_wstrlen(ret)))
		ret[prec] = 0;
	if (width <= (len = ft_wstrlen(ret)))
		return (ret);
	else
	{
		k = ret;
		ret = format_wstring_helper(form, ret, width, len);
		free(k);
	}
	return (ret);
}
