/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 08:54:30 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/25 11:53:36 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	len_num_itoa(long x)
{
	int		count;

	count = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		count++;
		x = x * -1;
	}
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		i;
	long	x;

	x = n;
	i = len_num_itoa(x);
	if (!(dst = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	dst[i--] = '\0';
	if (x == 0)
		dst[0] = 0 + '0';
	if (x < 0)
	{
		dst[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		dst[i] = x % 10 + '0';
		x = x / 10;
		i--;
	}
	return (dst);
}
