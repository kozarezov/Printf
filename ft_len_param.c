/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:15:26 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/25 23:36:50 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_len_param(va_list ar)
{
	int		count;
	va_list	safe;

	va_copy(safe, ar);
	count = len_num(va_arg(safe, int));
	va_end(safe);
	return (count);
}
