/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:03:55 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/01 16:52:30 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_clen(int n)
{
	int len;

	len = 0;
	while (n /= 10)
		len++;
	return (len + 1);
}

static char	*ft_revstr(int i, char *numstr2, char *numstr, int sign)
{
	int count;

	count = 0;
	if (sign)
		numstr2[count++] = '-';
	while (i >= 0)
		numstr2[count++] = numstr[i--];
	ft_strdel(&numstr);
	numstr2[count] = '\0';
	return (numstr2);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		count;
	char	*numstr;
	char	*numstr2;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = -1;
	sign = (n < 0) ? 1 : 0;
	n = (sign == 1) ? (n *= -1) : (n *= 1);
	count = ft_clen(n);
	if (!(numstr = ft_strnew(count)))
		return (NULL);
	if (!(numstr2 = ft_strnew(count)))
		return (NULL);
	while (i < count - 1)
	{
		numstr[++i] = (n % 10) + '0';
		n = n / 10;
	}
	return (ft_revstr(i, numstr2, numstr, sign));
}
