/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:46:42 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/23 09:06:51 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long int n, t_print *pf)
{
	if (n < 0)
	{
		ft_putchar('-', pf);
		ft_putnbr((n * -1), pf);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, pf);
		ft_putchar((n % 10 + '0'), pf);
	}
	else
		ft_putchar((n + '0'), pf);
}
