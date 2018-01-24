/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters_numeric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:00:53 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/24 09:22:52 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*perconv(char *form, va_list ap, int *len)
{
	int width;

	(void)ap;
	width = get_width(form);
	*len = (width > 1) ? width : 1;
	return ((wchar_t*)format_string(form, "%"));
}

static void helper_snum(char *form, int *len, char **snum)
{
	int up;

	up = ft_isupper(form[ft_strlen(form) - 1]);
	*len += 2;
	if (get_base(form) == 2 && up)
		*snum = ft_strjoin("0B", *snum);
	else if (get_base(form) == 2 && !up)
		*snum = ft_strjoin("0b", *snum);
	else if (get_base(form) == 8 && up)
		*snum = ft_strjoin("0O", *snum);
	else if (get_base(form) == 8 && !up)
		*snum = ft_strjoin("0o", *snum);
	else if (get_base(form) == 16 && up)
		*snum = ft_strjoin("0X", *snum);
	else if (get_base(form) == 16 && !up)
		*snum = ft_strjoin("0x", *snum);
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
	if (!(snum = add_prec_to_snum(form, pf_itoa_base(val,
		get_base(form), form))))
		return (0);
	if ((ft_strchr(flags, '#') && val != 0) || ft_strchr(form, 'p'))
	{
		helper_snum(form, len, &snum);
		// *len += 2;
		// if (get_base(form) == 2)
		// 	snum = ft_strjoin("0b", snum);
		// else if (get_base(form) == 8)
		// 	snum = ft_strjoin("0o", snum);
		// else if (get_base(form) == 16)
		// 	snum = ft_strjoin("0x", snum);
	}
	return ((wchar_t*)format_numeric(form, snum, width, len));
}
