/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_converters_numeric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:00:53 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:38 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*perconv(char *form, va_list ap, int *len)
{
	int width;

	(void)ap;
	width = get_width(form);
	*len = (width > 1) ? width : 1;
	return ((wchar_t*)format_string(form, "%"));
}

static void	helper_snum(char *form, int *len, char **snum)
{
	int		up;
	char	*keep;

	keep = *snum;
	up = ft_isupper(LCHR(form));
	*len += 2;
	if (get_base(form) == 2 && up)
		*snum = ft_strjoin("0B", *snum);
	else if (get_base(form) == 2 && !up)
		*snum = ft_strjoin("0b", *snum);
	else if (get_base(form) == 8 && up && (*len)--)
		*snum = ft_strjoin("0", *snum);
	else if (get_base(form) == 8 && !up && (*len)--)
		*snum = ft_strjoin("0", *snum);
	else if (get_base(form) == 16 && up)
		*snum = ft_strjoin("0X", *snum);
	else if (get_base(form) == 16 && !up)
		*snum = ft_strjoin("0x", *snum);
	free(keep);
}

wchar_t		*u_numconv(char *form, va_list ap, int *len)
{
	char				*snum;
	char				*flags;
	int					width;
	unsigned long long	val;
	char				*r;

	val = va_arg(ap, unsigned long long);
	if (!no_unallowed_flag("#+-0. hljzv", form))
		return (0);
	width = get_width(form);
	cast_u_numeric(&val, form);
	if (val == 0)
		return ((wchar_t*)format_numeric(form,
			add_prec_to_snum(form, "0"), width, len));
		r = pf_uitoa_base(val, get_base(form), form);
	if (!(snum = add_prec_to_snum(form, r)))
		return (0);
	free(r);
	flags = get_flags(form);
	if ((ft_strchr(flags, '#') && val != 0) || ft_strchr(form, 'p'))
		helper_snum(form, len, &snum);
	r = format_numeric(form, snum, width, len);
	free(flags);
	return ((wchar_t*)r);
}

wchar_t		*numconv(char *form, va_list ap, int *len)
{
	char			*snum;
	char			*flags;
	int				width;
	long long		val;
	char			*r;

	val = va_arg(ap, long long);
	if (!no_unallowed_flag("#+-0. hljzv", form))
		return (0);
	width = get_width(form);
	cast_numeric(&val, form);
	if (val == 0 && !ft_strchr(form, 'p'))
		return ((wchar_t*)format_numeric(form,
		add_prec_to_snum(form, "0"), width, len));
		r = pf_itoa_base(val, get_base(form), form);
	if (!(snum = add_prec_to_snum(form, r)))
		return (0);
	free(r);
	flags = get_flags(form);
	if ((ft_strchr(flags, '#') && val != 0) || ft_strchr(form, 'p'))
		helper_snum(form, len, &snum);
	r = format_numeric(form, snum, width, len);
	free(flags);
	return ((wchar_t*)r);
}
