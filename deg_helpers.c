/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:27:32 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/30 16:32:12 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		deg_octal(char *form)
{
	return (!((ft_strchr(form, 'o') || ft_strchr(form, 'O'))
	&& ((ft_strchr(form, '#') && ft_strchr(form, '0'))
	|| ft_strchr(form, '#'))));
}

int		deg_is_octal_conv(char *form)
{
	return ((form[ft_strlen(form) - 1] == 'o'
	|| form[ft_strlen(form) - 1] == 'O'));
}

int		deg_o_sh(char *snum, char *form, char *flags)
{
	return (!(ft_strequ(snum, "0") && (ft_strchr(form, 'o')
	|| ft_strchr(form, 'O')) && ft_strchr(flags, '0')));
}

int		deg_only_space(char *flags)
{
	return (ft_strchr(flags, ' ') && !ft_strchr(flags, '-')
	&& !ft_strchr(flags, '0') && !ft_strchr(flags, '+'));
}

void	deg_init_dg(int *dg0, int *dg1, int *dg2, int *dg3)
{
	*dg0 = 0;
	*dg1 = 0;
	*dg2 = -1;
	*dg3 = 0;
}
