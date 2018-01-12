/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:13:13 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/12 21:36:52 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ft_printf.h"

	char *perconv(char* form, va_list ap, int *len) {
		(void)ap;
		(void)form;

		*len = 1;
		return ("%");
	}

	char *intconv(char* form, va_list ap, int *len) {
		char *ret;

		(void)form;
		ret = ft_itoa(va_arg(ap, int));
		*len = ft_strlen(ret);
		return (ret);
	}

	char *charconv(char* form, va_list ap, int *len) {
		char *ret;

		(void)form;
		ret = ft_itos(va_arg(ap, int));
		*len = ft_strlen(ret);
		return (ret);
	}

	char *strconv(char *form, va_list ap, int *len)
	{
		char *ret;

		(void)form;
		ret = ft_strdup(va_arg(ap, char*));
		*len = ft_strlen(ret);
		return (ret);
	}
