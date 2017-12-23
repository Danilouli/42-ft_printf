/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:16:07 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 11:02:56 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		j;
	int		i;
	char	*s;

	i = 0;
	s = (char*)str;
	if (*to_find == 0)
		return ((char*)str);
	while (s[i] != 0)
	{
		j = 0;
		while (s[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == 0)
				return ((char*)(s + i));
		}
		i++;
	}
	return (0);
}
