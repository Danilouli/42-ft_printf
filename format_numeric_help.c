/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:27 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/24 19:15:01 by schmurz          ###   ########.fr       */
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

int		get_prec_chieur(char *form, char *snum)
{
	while (*form && *form != '.')
		form++;
	if (*form == '.' && ft_atoi(form + 1) == 0 && *(form + 2) != '0'
		&& *snum == '0' && !(*(snum + 1)))
		return (0);
	if (*form == '.')
	{
		if (ft_atoi(snum) >= 0)
			return ((ft_atoi(form + 1) == 0) ? 1 : ft_atoi(form + 1));
		else
			return ((ft_atoi(form + 1) == 0) ? 1 : (ft_atoi(form + 1) + 1));
	}
	return (1);
}

int		get_prec(char *form)
{
	while (*form && *form != '.')
		form++;
	if (*form == '.')
		return ((ft_atoi(form + 1) == 0) ? 1 : ft_atoi(form + 1));
	return (1);
}

char	*add_prec_to_snum(char *form, char *snum)
{
	int		prec;
	int		i;
	int		zer_to_add;
	char	*ret;
	int j;

	j = 0;
	prec = get_prec_chieur(form, snum);
	// printf("AVANT %s, PREC %d\n", snum, prec);
	i = 0;
	if ((prec = get_prec_chieur(form, snum)) < 2 ||
		(zer_to_add = prec - (int)ft_strlen(snum)) <= 0)
		return (((!prec && snum[0] == '0' && snum[1] == 0) && deg_octal(form))
			 ? "\0" : snum);
	if (!(ret = ft_strnew(zer_to_add + ft_strlen(snum))))
		return (0);
	if (ft_atoi(snum) < 0)
	{
		ret[i] = '-';
		i++;
		j++;
		zer_to_add += 1;
	}
	while (i < zer_to_add)
	{
		ret[i] = '0';
		i++;
	}
	while (i < (zer_to_add + (int)ft_strlen(snum)))
	{
		ret[i] = snum[j];
		i++;
		j++;
	}
	ret[i] = 0;
	// printf("APRES %s\n", ret);
	return (ret);
}

void		cast_numeric(long long *val, char *form)
{
	if (form)
	{
		if (ft_strstr(form, "hh"))
			*val = (char)(*val);
		else if (ft_strchr(form, 'h'))
			*val = (short)(*val);
		else if (ft_strstr(form, "ll") || ft_strchr(form, 'p'))
			*val = (long long)(*val);
		else if (ft_strchr(form, 'l'))
			*val = (long)(*val);
		else if (ft_strchr(form, 'j'))
			*val = (intmax_t)(*val);
		else if (ft_strchr(form, 'z'))
			*val = (size_t)(*val);
		else
			*val = (int)(*val);
	}
	else
		*val = (int)(*val);
	return ;
}
