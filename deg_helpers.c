/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:27:32 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/26 10:21:59 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int deg_octal(char *form)
{
  return (!((ft_strchr(form,'o') || ft_strchr(form,'O'))
  && ((ft_strchr(form, '#') && ft_strchr(form, '0'))
  || ft_strchr(form, '#'))));
}

int deg_is_octal_conv(char *form)
{
  return ((form[ft_strlen(form) - 1] == 'o'
  || form[ft_strlen(form) - 1] == 'O'));
}

int deg_only_space(char *flags)
{
  return (ft_strchr(flags, ' ') && !ft_strchr(flags, '-')
  && !ft_strchr(flags, '0') && !ft_strchr(flags, '.')
  && !ft_strchr(flags, '+'));
}
