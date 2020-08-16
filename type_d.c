/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:09:09 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:15:38 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(int nb)
{
	int digit;

	digit = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		digit++;
		nb /= 10;
	}
	return (digit);
}

static void	left_align_int(int nb, t_specif *specif)
{
	int i;
	int minus;
	int nb_len;

	i = 0;
	minus = 0;
	nb_len = count_digit(nb);
	if (nb < 0)
		ft_putchar_count('-');
	while (i++ < (specif->precision_value - nb_len))
		ft_putchar_count('0');
	i--;
	if (!(nb == 0 && specif->precision == 1 && specif->precision_value == 0))
		ft_putnbr_count(nb);
	while (i++ < (specif->width - nb_len))
		ft_putchar_count(' ');
}

static void	right_align_int(int nb, t_specif *specif)
{
	int i;
	int minus;
	int nb_len;

	i = 0;
	minus = 0;
	nb_len = count_digit(nb);
	while ((i < (specif->width - nb_len)) || (i < (specif->precision_value
	- nb_len)))
	{
		if (nb < 0 && minus == 0 && (i >= (specif->width - specif->
		precision_value)))
		{
			ft_putchar_count('-');
			minus++;
		}
		(i >= (specif->width - specif->precision_value)) ?
		ft_putchar_count('0') : ft_putchar_count(' ');
		i++;
	}
	if (nb < 0 && minus == 0)
		ft_putchar_count('-');
	if (!(nb == 0 && specif->precision == 1 && specif->precision_value == 0))
		ft_putnbr_count(nb);
}

void		type_d(va_list arg, t_specif *specif)
{
	int nb;
	int j;
	int minus;

	nb = va_arg(arg, int);
	j = 0;
	minus = 0;
	if (nb == 0 && specif->precision == 1 && specif->precision_value == 0)
		specif->width += 1;
	if (nb < 0)
		specif->width -= 1;
	if (specif->zero == 1 && specif->precision == 0 && specif->width != 0 &&
	!(nb == 0 && specif->precision == 1))
	{
		specif->precision = 1;
		specif->precision_value = specif->width;
	}
	if (specif->left == 0)
		right_align_int(nb, specif);
	if (specif->left == 1)
		left_align_int(nb, specif);
}
