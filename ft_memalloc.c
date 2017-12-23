/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:17:20 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:37:22 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	void *s;
	char *c;

	if ((s = malloc(size)))
	{
		c = (char*)s;
		while (size-- > 0)
			*c++ = 0;
		return (s);
	}
	else
		return (0);
}
