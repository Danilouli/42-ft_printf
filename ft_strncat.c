/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:47:59 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 18:42:26 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int len;

	len = ft_strlen(dest);
	while (*src && n-- > 0)
		dest[len++] = *src++;
	dest[len] = 0;
	return (dest);
}
