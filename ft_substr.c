/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:29:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2020/02/20 01:27:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rt;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(rt = (char *)malloc(sizeof(*rt) * (len + 1))))
		return (NULL);
	while (*s + start && i < len)
	{
		rt[i] = s[start];
		i++;
		start++;
	}
	rt[i] = '\0';
	return (rt);
}
