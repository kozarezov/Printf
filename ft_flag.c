/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:21:02 by ceccentr          #+#    #+#             */
/*   Updated: 2020/06/02 12:42:05 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	width_accuracy(t_print *pf, char *buf, int j)
{
	int		num;

	if (j != 0)
	{
		if (buf[j - 1] == '-')
			j--;
	}
	num = ft_atoi((char*)(buf + j));
	if (num < 0)
	{
		if (pf->point == 0)
			num = num * -1;
	}
	if (pf->point == 1)
		pf->acc = num;
	else
		pf->wid = num;
	while (ft_isdigit(buf[j]) == 1 || buf[j] == '-')
		j++;
	return (j - 1);
}

int			ft_flag(va_list ar, const char *s, int i, t_print *pf)
{
	char	*buf;
	int		j;

	j = 0;
	buf = ft_star(ar, s, i, pf);
	while (buf[j] != '\0')
	{
		while (buf[j] == '-' || buf[j] == '0')
		{
			if (buf[j] == '-' && pf->point == 0)
				pf->min = 1;
			else if (buf[j] == '0' && pf->point == 0)
				pf->null = 1;
			j++;
		}
		if (ft_isdigit(buf[j]) == 1)
			j = width_accuracy(pf, buf, j);
		if (buf[j] == '.')
			pf->point = 1;
		j++;
	}
	pf->null = (pf->min == 1) ? 0 : pf->null;
	i = i + ft_strlen(buf) - (pf->len_star);
	free(buf);
	return (i = ft_param(ar, s, i, pf));
}
