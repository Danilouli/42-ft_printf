/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:12:58 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/19 15:41:04 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *str;

	if (!(str = ft_strnew(n)))
		return (NULL);
	ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}
