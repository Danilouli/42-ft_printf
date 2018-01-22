/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:14:31 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/22 13:29:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	int	i;

	i = -1;
	if (c < 128)
		ft_putchar_fd(c, fd);
	else if (c < 2048 && !(i = 0))
		ft_putchar_fd((c >> 6) | 0b11000000, fd);
	else if (c < 65536 && (i = 1))
		ft_putchar_fd((c >> 12) | 0b11100000, fd);
	else if (c < 2097152 && (i = 2))
		ft_putchar_fd((c >> 18) | 0b11110000, fd);
	while (i > -1)
	{
		ft_putchar_fd(((c >> (6 * i)) & 0b00111111) | 0b10000000, fd);
		i--;
	}
}
