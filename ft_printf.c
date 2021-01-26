/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:45:54 by ceccentr          #+#    #+#             */
/*   Updated: 2020/06/02 12:21:38 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *str, ...)
{
	int		i;
	va_list	ar;
	t_print *pf;

	i = 0;
	va_start(ar, str);
	if (!(pf = (t_print*)malloc(sizeof(t_print))))
		return (0);
	pf->count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], pf);
		if (str[i] == '%')
		{
			ft_clear_list(pf);
			i++;
			i = ft_flag(ar, str, i, pf);
		}
		i++;
	}
	i = pf->count;
	free(pf);
	va_end(ar);
	return (i);
}
