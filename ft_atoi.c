/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:03:45 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/27 16:50:53 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			move_i(const char *str)
{
	int				i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int					ft_atoi(char *str)
{
	int				i;
	int				min;
	long long int	res;
	long long int	count;

	res = 0;
	min = 1;
	i = move_i(str);
	count = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = res;
		res = res * 10 + (str[i] - '0') * min;
		i++;
		if ((count < res && min == -1) || (count > res && min == 1))
			return (min == 1 ? -1 : 0);
	}
	return (res);
}
