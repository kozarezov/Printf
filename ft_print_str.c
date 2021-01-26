/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 10:36:41 by ceccentr          #+#    #+#             */
/*   Updated: 2020/06/01 11:40:29 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_print_str(va_list ar, t_print *pf)
{
	int			count;
	int			ac;
	char		*tmp;
	int			j;
	char		sim;

	j = 0;
	sim = (pf->null == 1) ? '0' : ' ';
	if (!(tmp = va_arg(ar, char*)))
	{
		pf->str_null = 1;
		tmp = ft_strdup("(null)");
	}
	ac = (pf->point == 0 || pf->acc < 0) ? ft_strlen(tmp) : pf->acc;
	count = (ac > ft_strlen(tmp)) ? pf->wid - ft_strlen(tmp) : pf->wid - ac;
	if (pf->min == 1)
		while (tmp[j] != '\0' && j < ac)
			ft_putchar(tmp[j++], pf);
	while (count-- > 0)
		ft_putchar(sim, pf);
	if (pf->min == 0)
		while (tmp[j] != '\0' && j < ac)
			ft_putchar(tmp[j++], pf);
	if (pf->str_null == 1)
		free(tmp);
}
