/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:57:41 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/14 20:51:08 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_strrchr(const char *src, int c)
{
	const	char	*begin;

	begin = src;
	while (*begin)
		begin += 1;
	if (!c)
		return ((char*)begin);
	while (--begin >= src)
	{
		if (*begin == (char)c)
			return ((char*)begin);
	}
	return (0);
}
