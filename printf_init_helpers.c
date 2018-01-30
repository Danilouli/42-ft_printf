/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_init_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:00:56 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 17:35:45 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_printf_flag(char c)
{
	return (ft_strchr("#0-+ .hljzvV123456789", c) != 0);
}

int				is_printf_conversion(char c)
{
	return (ft_strchr("sSpdDioOuUxXbBcC", c) != 0);
}

int				is_printf_arg(const char *format, char *info)
{
	int		c;
	char	*str;

	str = (char*)format;
	c = 0;
	*info = 'l';
	if (*str != '%')
		return (0);
	str++;
	while (*str && ++c)
	{
		if (!is_printf_flag(*str) && !is_printf_conversion(*str)
			&& *str != '%' && (*info = 'e'))
			return (-1);
		else if (*str == '%' && (*info = '%'))
			return (c);
		else if (is_printf_conversion(*str) && (*info = 'c'))
			return (c);
		str++;
	}
	return (-1);
}
