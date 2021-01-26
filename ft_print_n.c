/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:05:29 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/28 08:23:21 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			flag_num_no_p(t_print *pf, int x, long long int num)
{
	char			sim;

	sim = (pf->null == 1) ? '0' : ' ';
	if (pf->min == 1)
	{
		if (num < 0 && pf->null == 1)
		{
			num = num * -1;
			ft_putchar('-', pf);
		}
		ft_putnbr(num, pf);
		while (x-- > 0)
			ft_putchar(sim, pf);
	}
	else if (pf->min == 0)
	{
		if (num < 0 && pf->null == 1)
		{
			num = num * -1;
			ft_putchar('-', pf);
		}
		while (x-- > 0)
			ft_putchar(sim, pf);
		ft_putnbr(num, pf);
	}
}

static void			flag_num_p(t_print *pf, int x, int y, long long int num)
{
	if (num == 0 && y == 0 && x == 0)
		x = pf->wid - 1;
	if (num == 0 && y == 0)
		while (x-- >= 0)
			ft_putchar(' ', pf);
	else if (pf->min == 1)
	{
		if (pf->sign == 1)
			ft_putchar('-', pf);
		while (y-- > 0)
			ft_putchar('0', pf);
		ft_putnbr(num, pf);
		while (x-- > 0)
			ft_putchar(' ', pf);
	}
	else if (pf->min == 0)
	{
		while (x-- > 0)
			ft_putchar(' ', pf);
		if (pf->sign == 1)
			ft_putchar('-', pf);
		while (y-- > 0)
			ft_putchar('0', pf);
		ft_putnbr(num, pf);
	}
}

void				ft_print_n(va_list ar, t_print *pf, const char *s, int i)
{
	int				co_a;
	int				co_w;
	long long int	num;

	if (s[i] == 'u')
		num = va_arg(ar, unsigned int);
	else
		num = va_arg(ar, int);
	if ((co_a = pf->acc - len_num(num)) < 0)
		co_a = 0;
	if ((co_w = pf->wid - co_a - len_num(num)) < 0)
		co_w = 0;
	if (pf->point == 1)
	{
		if (num < 0)
		{
			num = num * -1;
			pf->sign = 1;
			co_a = ((pf->acc - len_num(num)) < 0) ? 0 : pf->acc - len_num(num);
			co_w = pf->wid - co_a - len_num(num * -1);
		}
		flag_num_p(pf, co_w, co_a, num);
	}
	else
		flag_num_no_p(pf, co_w, num);
}
