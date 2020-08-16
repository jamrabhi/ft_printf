/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:35:31 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:15:27 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c(va_list arg, t_specif *specif)
{
	char	c;
	int		j;

	c = va_arg(arg, int);
	j = 0;
	if (specif->left == 1)
		ft_putchar_count(c);
	while (j++ < (specif->width - 1))
		ft_putchar_count(' ');
	if (specif->left == 0)
		ft_putchar_count(c);
}
