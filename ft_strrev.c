/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:10:43 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/11 00:00:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		count_rev;
	char	tmp;

	count = 0;
	count_rev = ft_strlen(str);
	count_rev--;
	while (count_rev > count)
	{
		tmp = str[count_rev];
		str[count_rev] = str[count];
		str[count] = tmp;
		count_rev--;
		count++;
	}
	return (str);
}
