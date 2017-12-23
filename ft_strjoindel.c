/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:59:31 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/09 19:05:49 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoindel(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(r = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	while (s1[++i])
		r[i] = s1[i];
	while (s2[++j])
		r[i + j] = s2[j];
	r[i + j] = 0;
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (r);
}
