/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:24:03 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 23:48:52 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_printed;

void	do_print(va_list arg, const char *fmt)
{
	int			i;
	t_specif	specif;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			ft_putchar_count(fmt[i]);
		else
		{
			i++;
			ft_bzero(&specif, sizeof(specif));
			if (check_format((char*)fmt, i) == 0)
				return ;
			i = check_flag(fmt, i, &specif);
			i = check_width(arg, fmt, i, &specif);
			i = check_precis(arg, fmt, i, &specif);
			check_type(arg, fmt, i, &specif);
		}
		i++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;

	g_printed = 0;
	va_start(args, fmt);
	do_print(args, fmt);
	va_end(args);
	return (g_printed);
}
