/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:26:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:36 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count(long nb)
{
	unsigned int nb_cpy;

	nb_cpy = nb;
	if (nb < 0)
		nb_cpy = nb * -1;
	if (nb_cpy >= 0 && nb_cpy <= 9)
		ft_putchar_count(nb_cpy + '0');
	if (nb_cpy > 9)
	{
		ft_putnbr_count(nb_cpy / 10);
		ft_putnbr_count(nb_cpy % 10);
	}
}
