/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astrrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:33:02 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/13 17:11:57 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_astrrev(char **str)
{
	int		len;
	int		i;
	char	tmp;

	len = ft_strlen(*str);
	i = 0;
	while (i < (len / 2))
	{
		tmp = (*str)[i];
		(*str)[i] = (*str)[len - i - 1];
		(*str)[len - i - 1] = tmp;
		i++;
	}
	return ;
}
