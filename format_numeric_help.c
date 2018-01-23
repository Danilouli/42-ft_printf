/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:27 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/23 16:52:02 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		get_base(char *form)
{
	while (!(ft_strchr("vVoOxXbBp", *form)))
		form++;
	if (*form == 'b' || *form == 'B')
		return (2);
	if (*form == 'o' || *form == 'O')
		return (8);
	if (*form == 'x' || *form == 'X')
		return (16);
	if (*form == 'p')
		return (16);
	if (*form == 'v' || *form == 'V')
	{
		if (!ft_isdigit(*(form + 1)))
			return (10);
		else
			return ((ft_atoi(form + 1) == 0 || ft_atoi(form + 1) == 1) ?
					10 : ft_atoi(form + 1));
	}
	return (10);
}

int		get_prec(char *form)
{
	while (*form && *form != '.')
		form++;
	if (*form == '.')
		return ((ft_atoi(form + 1) == 0) ? 1 : ft_atoi(form + 1));
	return (0);
}

char	*add_prec_to_snum(char *form, char *snum)
{
	int		prec;
	int		i;
	int		zer_to_add;
	char	*ret;

	i = 0;
	if ((prec = get_prec(form)) < 2 ||
		(zer_to_add = prec - (int)ft_strlen(snum)) <= 0)
		return (snum);
	if (!(ret = ft_strnew(zer_to_add + ft_strlen(snum))))
		return (0);
	while (i < zer_to_add)
	{
		ret[i] = '0';
		i++;
	}
	while (i < (zer_to_add + (int)ft_strlen(snum)))
	{
		ret[i] = snum[i - zer_to_add];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
