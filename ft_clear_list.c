/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 10:03:15 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/30 10:16:27 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_clear_list(t_print *pf)
{
	pf->min = 0;
	pf->null = 0;
	pf->point = 0;
	pf->acc = 0;
	pf->wid = 0;
	pf->len_star = 0;
	pf->sign = 0;
	pf->str_null = 0;
}
