/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:52:29 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/28 10:16:46 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_unallowed_flag(char allowed_flags[], char *form)
{
	while (*form)
	{
		if (!(*(form + 1)))
			break ;
		if (*form != '%' && !ft_strchr(allowed_flags, *form)
				&& !ft_isdigit(*form))
			return (0);
		form++;
	}
	return (1);
}

int		get_width(char *form)
{
	while (*form && !(ft_isdigit(*form) && *form != '0')
		&& *form != 'v' && *form != 'V' && *form != '.')
		form++;
	if (ft_isdigit(*form) && *form != '0')
		return (ft_atoi(form));
	return (0);
}

char	*get_flags(char *form)
{
	int ct;

	ct = 0;
	form++;
	while (form[ct])
	{
		if (!form[ct + 1])
			break ;
		if ((ft_isdigit(form[ct]) && form[ct] != '0') || form[ct] == '%')
			break ;
		ct++;
	}
	if (ct)
		return (ft_strsub(form, 0, ct));
	return (ft_strdup("\0"));
}
