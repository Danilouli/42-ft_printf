/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:47:06 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 13:47:46 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;

	if (!(wstr = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	ft_bzero(wstr, size);
	return (wstr);
}
