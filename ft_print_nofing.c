/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nofing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 10:56:47 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/26 21:59:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_print_nothing(t_print *pf, const char *s, int i)
{
	int			count;
	int			width;
	char		sim;

	width = pf->wid;
	count = width - 1;
	sim = (pf->null == 1 && pf->min != 1) ? '0' : ' ';
	if (pf->min == 1)
		ft_putchar(s[i], pf);
	while (count-- > 0)
		ft_putchar(sim, pf);
	if (pf->min == 0)
		ft_putchar(s[i], pf);
}
