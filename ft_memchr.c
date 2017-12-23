/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:48:58 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:34:40 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char *s;

	s = (char*)src;
	while (n-- > 0)
		if (*s++ == (char)c)
			return (s - 1);
	return (0);
}
