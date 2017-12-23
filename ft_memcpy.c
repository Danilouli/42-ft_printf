/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:26:29 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:41:32 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dest);
}
