/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:07:12 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/13 22:10:55 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*r;
	char	*s;

	r = (char*)dest;
	s = (char*)src;
	i = 0;
	while (i < n)
	{
		r[i] = (char)s[i];
		if (r[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
