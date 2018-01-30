/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:27 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:06 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(char *form)
{
	while (!(ft_strchr("vVoOxXbBp", *form)))
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
		if (!ft_isdigit(*(form + 1)))
			return (10);
		else
			return ((ft_atoi(form + 1) == 0 || ft_atoi(form + 1) == 1) ?
					10 : ft_atoi(form + 1));
	}
	return (10);
}

void	cast_numeric(long long *val, char *form)
{
	if (form)
	{
		if (ft_strstr(form, "hh") && !ft_strchr("DOB", LCHR(form)))
			*val = (char)(*val);
		else if (ft_strchr(form, 'h') && !ft_strchr("DOB", LCHR(form)))
			*val = (short)(*val);
		else if (ft_strstr(form, "ll") || ft_strchr(form, 'p'))
			*val = (long long)(*val);
		else if (ft_strchr(form, 'l') || ft_strchr("DOB", LCHR(form)))
			*val = (long)(*val);
		else if (ft_strchr(form, 'j'))
			*val = (intmax_t)(*val);
		else if (ft_strchr(form, 'z'))
			*val = (size_t)(*val);
		else
			*val = (int)(*val);
	}
	else
		*val = (int)(*val);
	return ;
}

void	cast_u_numeric(unsigned long long *val, char *form)
{
	if (form)
	{
		if (ft_strstr(form, "hh") && !ft_strchr(form, 'U'))
			*val = (unsigned char)(*val);
		else if (ft_strchr(form, 'h') && !ft_strchr(form, 'U'))
			*val = (unsigned short)(*val);
		else if (ft_strstr(form, "ll") || ft_strchr(form, 'p'))
			*val = (unsigned long long)(*val);
		else if (ft_strchr(form, 'l') || LCHR(form) == 'U')
			*val = (unsigned long)(*val);
		else if (ft_strchr(form, 'j'))
			*val = (intmax_t)(*val);
		else if (ft_strchr(form, 'z'))
			*val = (size_t)(*val);
		else if (!ft_strchr(form, 'U'))
			*val = (unsigned int)(*val);
	}
	else
		*val = (unsigned int)(*val);
	return ;
}
