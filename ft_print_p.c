/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:58:08 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/29 10:55:56 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		flag_p_no_p(t_print *pf, int x, char *po)
{
	char		sim;
	int			j;

	j = 0;
	sim = (pf->null == 1) ? '0' : ' ';
	if (pf->min == 1)
	{
		while (po[j] != '\0')
			ft_putchar(po[j++], pf);
		while (x-- > 0)
			ft_putchar(sim, pf);
	}
	else
	{
		if (pf->null == 1)
			while (j != 2)
				ft_putchar(po[j++], pf);
		while (x-- > 0)
			ft_putchar(sim, pf);
		while (po[j] != '\0')
			ft_putchar(po[j++], pf);
	}
}

static void		flag_p_p(t_print *pf, int x, int y, char *po)
{
	int			j;

	j = 0;
	if (pf->min == 1)
	{
		while (j != 2)
			ft_putchar(po[j++], pf);
		while (y-- > 0)
			ft_putchar('0', pf);
		while (po[j] != '\0')
			ft_putchar(po[j++], pf);
		while (x-- > 0)
			ft_putchar(' ', pf);
	}
	else
	{
		while (x-- > 0)
			ft_putchar(' ', pf);
		while (j != 2)
			ft_putchar(po[j++], pf);
		while (y-- > 0)
			ft_putchar('0', pf);
		while (po[j] != '\0')
			ft_putchar(po[j++], pf);
	}
}

void			ft_print_p(va_list ar, t_print *pf)
{
	int			co_w;
	int			co_a;
	char		*po;
	int			j;

	j = 0;
	po = ft_itoa_base_u(va_arg(ar, unsigned long), 16);
	po = ft_tolower_str(ft_strjoin_f("0x", po));
	if ((co_a = pf->acc - ft_strlen(po) + 2) < 0)
		co_a = 0;
	if ((co_w = pf->wid - co_a - ft_strlen(po)) < 0)
		co_w = (pf->wid == 0 && pf->acc == 0 && po[2] == '0') ? -1 : 0;
	if (pf->point == 1 && pf->acc == 0 && po[2] == '0')
	{
		while (co_w-- >= 0)
			ft_putchar(' ', pf);
		while (j != 2)
			ft_putchar(po[j++], pf);
	}
	else if (pf->point == 1)
		flag_p_p(pf, co_w, co_a, po);
	else
		flag_p_no_p(pf, co_w, po);
	free(po);
	ft_clear_list(pf);
}
