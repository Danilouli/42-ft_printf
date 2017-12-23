/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:30:52 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 18:32:37 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcat(char *dest, const char *src)
{
	int len;

	len = ft_strlen(dest);
	while (*src)
		dest[len++] = *src++;
	dest[len] = 0;
	return (dest);
}
