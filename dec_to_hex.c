/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:56:23 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:14 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_to_hex(unsigned long nb)
{
	static char	rt[50];
	int			i;

	i = 0;
	if (nb == 0)
		return ("0");
	while (nb > 0)
	{
		if ((nb % 16) > 9)
			rt[i] = (nb % 16) + 87;
		else
			rt[i] = nb % 16 + '0';
		nb = (nb / 16);
		i++;
	}
	rt[i] = '\0';
	ft_strrev(rt);
	return (rt);
}
