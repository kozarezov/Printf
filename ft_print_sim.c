/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 10:35:27 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/25 23:29:34 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_print_sim(va_list ar, t_print *pf, const char *s, int i)
{
	int			count;
	int			width;
	char		sim;

	width = pf->wid;
	count = width - 1;
	sim = (pf->null == 1 && pf->min != 1) ? '0' : ' ';
	if (pf->min == 1)
	{
		if (s[i] == 'c')
			ft_putchar(va_arg(ar, int), pf);
		else
			ft_putchar('%', pf);
	}
	while (count-- > 0)
		ft_putchar(sim, pf);
	if (pf->min == 0)
	{
		if (s[i] == 'c')
			ft_putchar(va_arg(ar, int), pf);
		else
			ft_putchar('%', pf);
	}
}
