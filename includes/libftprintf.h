/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:38:26 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 11:42:23 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_issign(int c);
size_t				ft_strlen(const char *s);
int					ft_isupper(int c);
int					ft_islower(int c);
long long			ft_atoi(char const *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_striter(char *s, void (*f)(char*));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(char const *src);
char				*ft_strndup(const char *s, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strclr(char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_itoa_base(long long value, int base, int majmin);
void				ft_astrrev(char **str);
char				*ft_create_base(int b, int ismaj);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_lstlen(t_list *lst);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strrev(char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_isspacer(char c);
void				ft_lstreverse(t_list **beg_lst);
char				*ft_itos(int nb);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwchar(wchar_t chr);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putwstr(wchar_t const *s);
void				ft_putwendl_fd(wchar_t const *s, int fd);
void				ft_putwendl(wchar_t const *s);
wchar_t				*ft_itows(int nb);
wchar_t				*ft_wstrnew(size_t size);
size_t				ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrdup(wchar_t const *src);
int					ft_max(int a, int b);
int					ft_fprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					ft_numberchars(const char *str, char c);
void				ft_troll(void);

#endif
