/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:21:07 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:40:01 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(const char *fmt, int i)
{
	while (fmt[i])
	{
		if (fmt[i] == 'c' || fmt[i] == 's' || fmt[i] == 'p'
		|| fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'u'
		|| fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		check_flag(const char *fmt, int i, t_specif *specif)
{
	if (fmt[i] == '0' || fmt[i] == '-')
	{
		if (fmt[i] && fmt[i] == '-')
			specif->left = 1;
		if (fmt[i] && fmt[i] == '0')
			specif->zero = 1;
		i++;
		while (fmt[i] == '0' || fmt[i] == '-')
		{
			if (fmt[i] && fmt[i] == '-')
				specif->left = 1;
			if (fmt[i] && fmt[i] == '0')
				specif->zero = 1;
			i++;
		}
		if (specif->left == 1 && specif->zero == 1)
			specif->zero = 0;
	}
	return (i);
}

int		check_width(va_list arg, const char *fmt, int start, t_specif *specif)
{
	int		len;
	int		i;
	char	*tmp;

	len = 0;
	i = start;
	if (fmt[i] == '*')
	{
		specif->width = va_arg(arg, int);
		if (specif->width < 0)
		{
			specif->left = 1;
			specif->zero == 1 ? specif->zero = 0 : 0;
			specif->width *= -1;
		}
		return (i + 1);
	}
	while (ft_isdigit(fmt[i]) == 1 && i++)
		len++;
	tmp = ft_substr(fmt, start, len);
	specif->width = ft_atoi(tmp);
	free(tmp);
	return (i);
}

int		check_precis(va_list arg, const char *fmt, int start, t_specif *specif)
{
	int		i;
	int		len;
	char	*tmp;

	i = start;
	len = 0;
	if (fmt[i] == '.')
	{
		specif->precision = 1;
		i++;
		if (fmt[i] == '*')
		{
			specif->precision_value = va_arg(arg, int);
			specif->precision_value < 0 ? specif->precision = 0 : 0;
			specif->precision_value < 0 ? specif->precision_value = 0 : 0;
			return (i + 1);
		}
		start++;
		while (ft_isdigit(fmt[i]) == 1 && i++)
			len++;
		tmp = ft_substr(fmt, start, len);
		specif->precision_value = ft_atoi(tmp);
		free(tmp);
	}
	return (i);
}

void	check_type(va_list arg, const char *fmt, int i, t_specif *specif)
{
	if (fmt[i] == 's')
		type_s(arg, specif);
	if (fmt[i] == 'c')
		type_c(arg, specif);
	if (fmt[i] == 'd' || fmt[i] == 'i')
		type_d(arg, specif);
	if (fmt[i] == 'p')
		type_p(arg, specif);
	if (fmt[i] == 'u')
		type_u(arg, specif);
	if (fmt[i] == '%')
		type_percent(specif);
	if (fmt[i] == 'x')
		type_x(arg, specif);
	if (fmt[i] == 'X')
		type_x_upper(arg, specif);
}
