/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:05:01 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/14 20:36:19 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dest;
	s = (char*)src;
	i = -1;
	if (s < d)
	{
		while ((--n + 1) > 0)
			*(d + n) = *(s + n);
	}
	else
	{
		while (++i < n)
			*(d + i) = *(s + i);
	}
	return (dest);
}
