/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:48:59 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:47:08 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	o_u_b_x_len(uintmax_t n, int system)
{
	size_t		len;

	len = 1;
	while (n >= (unsigned long)system)
	{
		n = n / system;
		len++;
	}
	return (len);
}

size_t	intmax_len(intmax_t n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*itoa_intmax(intmax_t n)
{
	char		*str;
	int			num_len;

	num_len = intmax_len(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		if (n < 0)
		{
			str[--num_len] = -(n % 10) + 48;
			n /= 10;
			n = -n;
		}
		else
		{
			str[--num_len] = n % 10 + 48;
			n /= 10;
		}
	}
	return (str);
}

int		atoi_start_i(char *str, int *i)
{
	int		number;

	number = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + str[*i] - 48;
		(*i)++;
	}
	(*i)--;
	return (number);
}

char	*strdup_l(char *s, t_data_struct *data)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s);
	if (data->precision && data->precision_width < len)
		len = data->precision_width;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
