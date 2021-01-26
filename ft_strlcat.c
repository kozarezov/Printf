/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:30:59 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/24 15:45:20 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[j] != '\0')
		j++;
	while (dst[k] != '\0' && k < size)
		k++;
	if (size == 0)
		return (j);
	if (size <= k)
		return (j + size);
	while (i < (size - k - 1) && src[i] != '\0')
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (j + k);
}
