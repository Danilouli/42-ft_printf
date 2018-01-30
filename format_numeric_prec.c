/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numeric_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:32:02 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:23 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		j;

	j = 0;
	prec = get_prec_chieur(form, snum);
	i = 0;
	if ((prec = get_prec_chieur(form, snum)) < 2 ||
		(zer_to_add = prec - (int)ft_strlen(snum)) <= 0)
		return (((!prec && ft_strequ(snum, "0")) && deg_octal(form)) ?
		ft_strdup("\0") : ft_strdup(snum));
		if (!(ret = ft_strnew(zer_to_add + ft_strlen(snum))))
		return (0);
	if (ft_atoi(snum) < 0 && j++ >= 0 && zer_to_add++ >= 0)
		ret[i++] = '-';
	while (i < zer_to_add)
		ret[i++] = '0';
	while (i < (zer_to_add + (int)ft_strlen(snum)))
		ret[i++] = snum[j++];
	ret[i] = 0;
	return (ret);
}
