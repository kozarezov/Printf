/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:42:13 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/06/01 11:40:12 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_list
{
	int			min;
	int			null;
	int			point;
	int			wid;
	int			acc;
	int			len_star;
	int			sign;
	int			count;
	int			str_null;
}				t_print;
int				ft_printf(const char *str, ...);
void			ft_putchar(char c, t_print *pf);
void			ft_putnbr(long int n, t_print *pf);
void			ft_putstr(char *s, t_print *pf);
char			*ft_itoa_base_u(unsigned long int value, int base);
char			*ft_tolower_str(char *str);
int				ft_flag(va_list ar, const char *s, int i, t_print *pf);
int				ft_atoi(char *str);
int				ft_strlen(const char *str);
int				ft_len_param(va_list ar);
int				ft_isdigit(int c);
int				len_num(long long int x);
char			*ft_star(va_list ar, const char *s, int i, t_print *pf);
int				ft_isalpha(int c);
char			*ft_itoa(int n);
void			ft_clear_list(t_print *pf);
void			ft_print_sim(va_list ar, t_print *pf, const char *s, int i);
void			ft_print_str(va_list ar, t_print *pf);
void			ft_print_n(va_list ar, t_print *pf, const char *s, int i);
int				ft_param(va_list ar, const char *s, int i, t_print *pf);
void			ft_print_hex(va_list ar, t_print *pf, const char *s, int i);
char			*ft_strjoin_f(char const *s1, char *s2);
int				ft_strlcat(char *dst, const char *src, int size);
int				ft_strlcpy(char *dst, const char *src, int size);
void			ft_print_p(va_list ar, t_print *pf);
char			*ft_strdup(const char *str);
void			ft_print_nothing(t_print *pf, const char *s, int i);

#endif
