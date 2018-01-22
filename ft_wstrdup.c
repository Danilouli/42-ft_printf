/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:50:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 13:53:27 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t		*ft_wstrdup(wchar_t const *src)
{
	wchar_t	*dup;
	int		i;

	i = -1;
	if (!(dup = ft_wstrnew(ft_wstrlen(src))))
		return (0);
	while (src[++i] && (dup[i] = src[i]))
		;
	dup[i] = 0;
	return (dup);
}
