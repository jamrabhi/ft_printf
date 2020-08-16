/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 03:55:19 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:04 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_to_hex_upper(long nb)
{
	static char	rt[50];
	int			i;

	i = 0;
	if (nb == 0)
		return ("0");
	while (nb > 0)
	{
		if ((nb % 16) > 9)
			rt[i] = (nb % 16) + 55;
		else
			rt[i] = nb % 16 + '0';
		nb = (nb / 16);
		i++;
	}
	rt[i] = '\0';
	ft_strrev(rt);
	return (rt);
}
