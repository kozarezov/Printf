/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:07:28 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/28 08:37:34 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char					*ft_itoa_base_u(unsigned long int value, int base)
{
	char				*s;
	int					i;
	unsigned long int	n;

	if (value == 0)
		return (ft_strdup("0"));
	n = value;
	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = value;
	while (n != 0)
	{
		s[--i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}
