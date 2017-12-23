/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:21:13 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/14 21:00:30 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strmap(char const *str, char (*f)(char))
{
	char	*s;
	int		i;

	if (str == 0)
		return (0);
	if (!(s = ft_strdup(str)))
		return (0);
	i = -1;
	while (str[++i])
		s[i] = (*f)(str[i]);
	return (s);
}
