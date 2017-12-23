/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:33:30 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/14 21:01:31 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = -1;
	if (s == 0)
		return (0);
	if (!(r = (char*)malloc(len + 1)))
		return (0);
	while (++i < len)
		r[i] = s[start + i];
	r[i] = 0;
	return (r);
}
