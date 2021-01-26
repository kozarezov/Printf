/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:44:41 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/27 11:03:18 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			len_num(long long int x)
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
