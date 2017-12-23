/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:36:57 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:39:53 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*r;

	r = (char*)s;
	i = 0;
	while (i < n)
		r[i++] = (char)c;
	return (s);
}
