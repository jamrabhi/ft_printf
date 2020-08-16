/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:39:47 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:42:33 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	left_align(unsigned int nb, t_specif *specif)
{
	int		i;
	char	*hex;
	int		hex_len;

	i = 0;
	hex = dec_to_hex(nb);
	hex_len = ft_strlen(hex);
	while (i++ < (specif->precision_value - hex_len))
		ft_putchar_count('0');
	i--;
	if (!(nb == 0 && specif->precision == 1 && specif->precision_value == 0))
		ft_putstr_count(hex);
	while (i++ < (specif->width - hex_len))
		ft_putchar_count(' ');
}

static void	right_align(unsigned int nb, t_specif *specif)
{
	int		i;
	char	*hex;
	int		hex_len;

	i = 0;
	hex = dec_to_hex(nb);
	hex_len = ft_strlen(hex);
	while ((i < (specif->width - hex_len)) || (i < (specif->precision_value
	- hex_len)))
	{
		(i >= (specif->width - specif->precision_value)) ?
		ft_putchar_count('0') : ft_putchar_count(' ');
		i++;
	}
	if (!(nb == 0 && specif->precision == 1 && specif->precision_value == 0))
		ft_putstr_count(hex);
}

void		type_x(va_list arg, t_specif *specif)
{
	unsigned int nb;

	nb = va_arg(arg, unsigned int);
	if (nb == 0 && specif->precision == 1 && specif->precision_value == 0)
		specif->width += 1;
	if (specif->zero == 1 && specif->precision == 0 && specif->width != 0
	&& !(nb == 0 && specif->precision == 1))
	{
		specif->precision = 1;
		specif->precision_value = specif->width;
	}
	if (specif->left == 0)
		right_align(nb, specif);
	if (specif->left == 1)
		left_align(nb, specif);
}
