/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:40:23 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/26 21:59:14 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_param(va_list ar, const char *s, int i, t_print *pf)
{
	if (s[i] == 'c' || s[i] == '%')
		ft_print_sim(ar, pf, s, i);
	else if (s[i] == 's')
		ft_print_str(ar, pf);
	else if (s[i] == 'u' || s[i] == 'd' || s[i] == 'i')
		ft_print_n(ar, pf, s, i);
	else if (s[i] == 'x' || s[i] == 'X')
		ft_print_hex(ar, pf, s, i);
	else if (s[i] == 'p')
		ft_print_p(ar, pf);
	else
		ft_print_nothing(pf, s, i);
	return (i);
}
