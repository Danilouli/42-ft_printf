/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:20:47 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 13:30:12 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putwendl_fd(wchar_t const *s, int fd)
{
	ft_putwstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
