/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:23:59 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/01 16:32:29 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long i;
	long long a;
	long long neg;

	i = 0;
	neg = 1;
	a = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((neg > 0) && (a * neg < 0))
			return (-1);
		if ((neg < 0) && (a * neg > 0))
			return (0);
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (a * neg);
}
