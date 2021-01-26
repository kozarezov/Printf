/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 10:40:53 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/28 08:08:40 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		flag_hex_no_p(t_print *pf, int x, char *tmp)
{
	char		sim;
	int			j;

	j = 0;
	sim = (pf->null == 1) ? '0' : ' ';
	if (pf->min == 1)
	{
		while (tmp[j] != '\0')
			ft_putchar(tmp[j++], pf);
		while (x-- > 0)
			ft_putchar(sim, pf);
	}
	else
	{
		while (x-- > 0)
			ft_putchar(sim, pf);
		while (tmp[j] != '\0')
			ft_putchar(tmp[j++], pf);
	}
}

static void		flag_hex_p(t_print *pf, int x, int y, char *tmp)
{
	int			j;

	j = 0;
	if (pf->min == 1)
	{
		while (y-- > 0)
			ft_putchar('0', pf);
		while (tmp[j] != '\0')
			ft_putchar(tmp[j++], pf);
		while (x-- > 0)
			ft_putchar(' ', pf);
	}
	else
	{
		while (x-- > 0)
			ft_putchar(' ', pf);
		while (y-- > 0)
			ft_putchar('0', pf);
		while (tmp[j] != '\0')
			ft_putchar(tmp[j++], pf);
	}
}

void			ft_print_hex(va_list ar, t_print *pf, const char *s, int i)
{
	int			co_w;
	int			co_a;
	char		*tmp;

	tmp = ft_itoa_base_u(va_arg(ar, unsigned int), 16);
	if (s[i] == 'x')
		ft_tolower_str(tmp);
	if ((co_a = pf->acc - ft_strlen(tmp)) < 0)
		co_a = 0;
	if ((co_w = pf->wid - co_a - ft_strlen(tmp)) < 0)
		co_w = (pf->wid == 0 && pf->acc == 0 && tmp[0] == '0') ? -1 : 0;
	if (pf->point == 1 && pf->acc == 0 && tmp[0] == '0')
	{
		while (co_w-- >= 0)
			ft_putchar(' ', pf);
	}
	else if (pf->point == 1)
		flag_hex_p(pf, co_w, co_a, tmp);
	else
		flag_hex_no_p(pf, co_w, tmp);
	free(tmp);
}
