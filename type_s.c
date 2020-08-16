/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:36:32 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:15:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(va_list arg, t_specif *specif)
{
	char	*str;
	int		j;
	int		str_len;

	str = va_arg(arg, char*);
	if (!str)
		str = "(null)";
	j = 0;
	if (specif->precision == 1 && specif->precision_value >= 0)
		str = ft_substr(str, 0, specif->precision_value);
	str_len = ft_strlen(str);
	if (specif->left == 1)
		ft_putstr_count(str);
	if (specif->width > str_len)
		while (j++ != (specif->width - str_len))
			specif->zero == 1 ? ft_putchar_count('0') :
			ft_putchar_count(' ');
	if (specif->left == 0)
		ft_putstr_count(str);
	if (specif->precision == 1 && specif->precision_value >= 0)
		free(str);
}
