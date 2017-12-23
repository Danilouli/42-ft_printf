/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:52:53 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/13 19:25:19 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_issign(int c)
{
	return (('*' == c || c == '+' || c == '-' || c == '/') ? c : 0);
}