/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:26:13 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/27 10:48:44 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoin_f(char const *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(dst = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(dst, s1, (len_s1 + 1));
	ft_strlcat(dst, s2, (len_s1 + len_s2 + 1));
	free(s2);
	return (dst);
}
