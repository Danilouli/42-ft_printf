/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:50:39 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/11 18:48:27 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PFARGS(X) ((t_pfargs*)(g_pfargs->content))->X

# include "libftprintf.h"

typedef struct		s_pfargs
{
	char			*value;
	char			type;
	int				len;
}					t_pfargs;

typedef struct		s_conv
{
	char sign;
	char* (*convertor)(char*, va_list);
}									t_conv;


void count_printf_args(const char *form);
int is_printf_arg(const char *pt);
char *intconv(char* form, va_list ap);
char *charconv(char* form, va_list ap);
char *strconv(char* form, va_list ap);


t_list *g_pfargs;

#endif
