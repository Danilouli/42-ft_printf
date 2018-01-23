/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:42:05 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 16:04:24 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itos(int nb)
{
	char *str;

	if (!nb)
		return (ft_strdup("\0"));
	if (!(str = ft_strnew(2)))
		return (0);
	str[0] = (char)nb;
	str[1] = 0;
	return (str);
}
