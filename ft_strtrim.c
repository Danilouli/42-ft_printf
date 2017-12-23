/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:43:59 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/14 21:21:13 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		fw;
	int		lw;

	i = -1;
	fw = 0;
	if (!s)
		return (0);
	lw = (int)(ft_strlen(s) - 1);
	while (lw >= 0 && s[lw] && ft_isspacer(s[lw]))
		lw--;
	while ((fw <= (int)ft_strlen(s) - 1) && s[fw] && ft_isspacer(s[fw]))
		fw++;
	if (lw < fw)
		return (ft_strdup("\0"));
	if (!(r = (char*)malloc(lw - fw + 2)))
		return (0);
	while (++i < lw - fw + 1)
		r[i] = s[fw + i];
	r[i] = 0;
	return (r);
}
