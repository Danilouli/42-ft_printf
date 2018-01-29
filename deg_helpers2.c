/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:07:28 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/26 16:20:36 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int deg_nf(char *form, char *fg, long long *val, char *sn)
{
  return(!ft_strchr(form, 'u') && !ft_strchr(form, 'U')
  && (*val = ft_atoi(sn)) >= 0 && ft_strchr(fg, '+')
  && ft_strchr(fg, '0') && get_prec(form) < 2);
}

int deg_nf2(char *form, char *fg, long long *val, char *sn)
{
    return (!ft_strchr(form, 'u') && !ft_strchr(form, 'U')
    && (*val = ft_atoi(sn)) < 0 && ft_strchr(fg, '0') && (get_prec(form) < 2));
}

int deg_nf3(char *form, char *fg, char *r, long long val)
{
  return (!ft_strchr(form, 'u') && !ft_strchr(form, 'U')
  && (r[0] != '+') && ft_strchr(fg, '+') && val >= 0);
}
