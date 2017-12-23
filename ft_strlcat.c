/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:53:34 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 21:23:50 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] && i < size)
		i++;
	end = i;
	while (src[i - end] && i < size - 1)
	{
		dest[i] = src[i - end];
		i++;
	}
	if (end < size)
		dest[i] = '\0';
	return (end + ft_strlen(src));
}
