/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:50:39 by dsaadia           #+#    #+#             */
/*   Updated: 2017/12/23 19:07:28 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define PFARGS(X) (g_pfargs->((t_pfargs*)content))->X

# include "libftprintf.h"

typedef struct		s_pfargs
{
	char			*value;
	char			type;
}					t_pfargs;

t_list *g_pfargs;

void count_printf_args(char *form);

#endif
