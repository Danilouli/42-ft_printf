/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/11 18:02:03 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ft_printf.h"

	char *intconv(char* form, va_list ap) {
		(void)form;
		return ft_itoa(va_arg(ap, int));
	}

	char *charconv(char* form, va_list ap) {
		(void)form;
		return ft_itos(va_arg(ap, int));
	}

	char *strconv(char *form, va_list ap)
	{
		(void)form;
		return ft_strdup(va_arg(ap, char*));
	}
