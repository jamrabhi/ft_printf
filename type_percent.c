/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:22:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:17:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_percent(t_specif *specif)
{
	int j;

	j = 0;
	if (specif->left == 1)
		ft_putchar_count('%');
	if (specif->width > 1)
		while (j++ != (specif->width - 1))
			specif->zero == 1 ? ft_putchar_count('0') :
			ft_putchar_count(' ');
	if (specif->left == 0)
		ft_putchar_count('%');
}
