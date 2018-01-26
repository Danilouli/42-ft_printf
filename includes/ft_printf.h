/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:50:39 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/26 15:11:30 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PFARGS(X) ((t_pfargs*)(g_pfargs->content))->X
# define LCHR(S) S[ft_strlen(S) - 1]

# include "libftprintf.h"

typedef struct		s_pfargs
{
	char			*value;
	char			type;
	int				len;
	int				index;
}					t_pfargs;

typedef struct		s_conv
{
	char			sign;
	wchar_t			*(*convertor)(char*, va_list, int*);
}					t_conv;

int					count_printf_args(const char *form);
int					is_printf_arg(const char *pt, char *info);
wchar_t				*perconv(char *form, va_list ap, int *len);
wchar_t				*numconv(char *form, va_list ap, int *len);
wchar_t				*charconv(char *form, va_list ap, int *len);
wchar_t				*strconv(char *form, va_list ap, int *len);
wchar_t				*wcharconv(char *form, va_list ap, int *len);
wchar_t				*wstrconv(char *form, va_list ap, int *len);
int					no_unallowed_flag(char allowed_flags[5], char *form);
int					get_width(char *form);
char				*get_flags(char *form);
char				*format_numeric(char *flags, char *snum,
					int width, int *lenk);
void				cast_numeric(long long *val, char *form);
char				*get_flags(char *form);
int					get_base(char *form);
char				*add_prec_to_snum(char *form, char *snum);
int					ft_fprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
char				*format_string(char *form, char *str);
wchar_t				*format_wstring(char *form, wchar_t *str);
char					*pf_itoa_base(long long value, int base, char *form);
int						get_prec(char *form);
int						get_prec_chieur(char *form, char *snum);
int deg_octal(char *form);
int deg_is_octal_conv(char *form);
int deg_only_space(char *flags);
void		cast_u_numeric(unsigned long long *val, char *form);
wchar_t	*u_numconv(char *form, va_list ap, int *len);
char		*pf_uitoa_base(unsigned long long value, int base, char *fm);
wchar_t	*u_numconv(char *form, va_list ap, int *len);
int		get_prec_str(char *form);

t_list				*g_pfargs;

#endif
