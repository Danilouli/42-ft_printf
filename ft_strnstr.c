/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:34:33 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 13:58:23 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		j;
	size_t		i;
	size_t		ct;
	char		*s;

	i = 0;
	s = (char*)str;
	ct = 0;
	if (!*to_find)
		return ((char*)str);
	while (s[i] && ct < n)
	{
		j = 0;
		ct = i;
		while (s[i + j] == to_find[j] && ct < n)
		{
			j++;
			if (!to_find[j])
				return ((char*)(s + i));
			ct++;
		}
		i++;
	}
	return (0);
}
