/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters_numeric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:00:53 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 17:00:14 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*perconv(char *form, va_list ap, int *len)
{
	(void)ap;
	(void)form;
	*len = 1;
	return ((wchar_t*)"%");
}

wchar_t	*numconv(char *form, va_list ap, int *len)
{
	char			*snum;
	char			*flags;
	int				width;
	long long		val;

	val = va_arg(ap, long long);
	if (!no_unallowed_flag("#+-0. hljzv", form))
		return (0);
	flags = get_flags(form);
	width = get_width(form);
	cast_numeric(&val, form);
	if (!(snum = add_prec_to_snum(form, ft_itoa_base(val,
		get_base(form), ft_isupper(form[ft_strlen(form) - 1])))))
		return (0);
	if (ft_strchr(flags, '#') || ft_strchr(form, 'p'))
	{
		if (get_base(form) == 2)
			snum = ft_strjoin("0b", snum);
		else if (get_base(form) == 8)
			snum = ft_strjoin("0o", snum);
		else if (get_base(form) == 16)
			snum = ft_strjoin("0x", snum);
	}
	return ((wchar_t*)format_numeric(form, snum, width, len));
}
