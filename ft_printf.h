/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:25:26 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:56:39 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

extern int		g_printed;

typedef struct	s_specif
{
	int width;
	int precision;
	int precision_value;
	int left;
	int zero;
}				t_specif;

int				ft_printf(const char *fmt, ...);

int				check_format(const char *fmt, int i);
int				check_flag(const char *fmt, int i, t_specif *specif);
int				check_width(va_list arg, const char *fmt, int start,
				t_specif *specif);
int				check_precis(va_list arg, const char *fmt, int start,
				t_specif *specif);
void			check_type(va_list arg, const char *fmt, int i,
				t_specif *specif);

void			type_s(va_list arg, t_specif *specif);
void			type_c(va_list arg, t_specif *specif);
void			type_d(va_list arg, t_specif *specif);
void			type_p(va_list arg, t_specif *specif);
void			type_x(va_list arg, t_specif *specif);
void			type_x_upper(va_list arg, t_specif *specif);
void			type_percent(t_specif *specif);
void			type_u(va_list arg, t_specif *specif);

char			*dec_to_hex(unsigned long nb);
char			*dec_to_hex_upper(long nb);

void			ft_putchar_count(char c);
void			ft_putstr_count(char *str);
void			ft_putnbr_count(long n);
void			ft_putunbr_count(unsigned int nb);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strrev(char *str);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
