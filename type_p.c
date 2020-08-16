/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:45:25 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:15:49 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_p(va_list arg, t_specif *specif)
{
	void	*adress_arg;
	char	*adress;
	int		j;
	int		str_len;

	adress_arg = va_arg(arg, void*);
	if (adress_arg == NULL && specif->precision == 1)
		adress = ft_strjoin("0x", "\0");
	else
		adress = ft_strjoin("0x", dec_to_hex((unsigned long)adress_arg));
	j = 0;
	str_len = ft_strlen(adress);
	if (specif->left == 1)
		ft_putstr_count(adress);
	if (specif->width > str_len)
		while (j++ < (specif->width - str_len))
			ft_putchar_count(' ');
	if (specif->left == 0)
		ft_putstr_count(adress);
	free(adress);
}
