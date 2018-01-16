/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:50:39 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/16 16:42:45 by dsaadia          ###   ########.fr       */
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
	int 			index;
}					t_pfargs;

typedef struct		s_conv
{
	char sign;
	char* (*convertor)(char*, va_list, int*);
}									t_conv;

int count_printf_args(const char *form);
int is_printf_arg(const char *pt, char *info);
char *perconv(char* form, va_list ap, int *len);
char *intconv(char* form, va_list ap, int *len);
char *charconv(char* form, va_list ap, int *len);
char *strconv(char* form, va_list ap, int *len);
int no_unallowed_flag(char allowed_flags[5], char *form);
int get_width(char *form);
char* get_flags(char *form);
char *format_numeric(char *flags, char *snum, int width, int *lenk);
void cast_numeric(long long *val, char *flags);
int get_prec(char *form);
char* get_flags(char *form);
char *add_prec_to_snum(char *form, char *snum);

t_list *g_pfargs;

#endif
