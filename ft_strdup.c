/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:25:54 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:43:43 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strdup(char const *src)
{
	char	*dup;
	int		i;

	i = -1;
	if (!(dup = (char*)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (0);
	while (src[++i] && (dup[i] = src[i]))
		;
	dup[i] = 0;
	return (dup);
}
