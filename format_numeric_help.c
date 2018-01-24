/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:27 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/24 11:41:57 by schmurz          ###   ########.fr       */
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
	// printf("III-->%c , %lld , %c, %c\n", *form, ft_atoi(form + 1), *snum, *(snum + 1));
	if (*form == '.' && ft_atoi(form + 1) == 0 && *snum == '0' && !(*(snum + 1)))
	{
		return (0);
	}
	if (*form == '.')
		return ((ft_atoi(form + 1) == 0) ? 1 : ft_atoi(form + 1));
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

	i = 0;
	prec = get_prec_chieur(form, snum);
	// printf("FHUIQHF%d\n", get_prec_chieur(form, snum));
	// printf("ForF%s\n", form);
	// printf("qdqfqf%d\n", (!prec && snum[0] == '0' && snum[1] == 0) && !((ft_strchr(form,'o') || ft_strchr(form,'O')) && (ft_strchr(form, '#') || ft_strchr(form, '0'))));
	// printf("ForF%s\n", snum);
	if ((prec = get_prec_chieur(form, snum)) < 2 ||
		(zer_to_add = prec - (int)ft_strlen(snum)) <= 0)
		{
			if ((!prec && snum[0] == '0' && snum[1] == 0) && !((ft_strchr(form,'o') || ft_strchr(form,'O')) && ((ft_strchr(form, '#') && ft_strchr(form, '0')) || ft_strchr(form, '#'))))
			{
				// ft_putendl("huhu\n");
				return ("\0");
			}
			else
			{
				// ft_putendl("hihi\n");
				// ft_putendl(snum);
				// ft_putendl("hihi\n");
				return (snum);
			}
		}
		// return (((!prec && snum[0] == '0' && snum[1] == 0) && !((ft_strchr(form,'o') || ft_strchr(form,'O')) && (ft_strchr(form, '#') || (ft_strchr(form, '0')))))
		// 	 ? "\0" : snum);
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
