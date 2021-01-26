/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:44:21 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/28 07:25:21 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	isbuf(const char *s, int i)
{
	if (s[i] >= '0' && s[i] <= '9')
		return (1);
	if (s[i] == '-' || s[i] == '.' || s[i] == '*')
		return (1);
	if (s[i] == '+' || s[i] == ' ' || s[i] == '#')
		return (1);
	else
		return (0);
}

static int	buf_star(va_list ar, t_print *pf, int j, char *buf)
{
	char	*dst;
	int		k;

	k = 0;
	dst = ft_itoa(va_arg(ar, int));
	pf->len_star += (ft_strlen(dst) - 1);
	while (dst[k] != '\0')
		buf[j++] = dst[k++];
	free(dst);
	return (j);
}

static int	len_ft_star(va_list ar, const char *s, int i)
{
	int		size;

	size = 0;
	while (isbuf(s, i) == 1)
	{
		if (s[i] == '*')
			size = size + ft_len_param(ar);
		else
			size++;
		i++;
	}
	return (size);
}

char		*ft_star(va_list ar, const char *s, int i, t_print *pf)
{
	char	*buf;
	int		size;
	int		j;

	j = 0;
	size = len_ft_star(ar, s, i);
	if (!(buf = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (isbuf(s, i) == 1)
	{
		if (s[i] == '*')
			j = buf_star(ar, pf, j, buf);
		else
			buf[j++] = s[i];
		i++;
	}
	buf[j] = '\0';
	return (buf);
}
