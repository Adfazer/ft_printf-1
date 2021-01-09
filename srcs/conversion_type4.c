/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:44:18 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 22:44:19 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		strlen_and_zero(char *str, t_data_struct *data)
{
	data->len = ft_strlen(str);
	str = zero_precision(str, data);
	data->len = ft_strlen(str);
}

void		edit_flag2(t_data_struct *data)
{
	data->precision_width = 0;
	data->precision = 1;
	data->zero = 0;
	data->sharp = 0;
	if (float_nan(data))
	{
		data->plus = 0;
		data->is_nan = 1;
	}
	else
	{
		data->is_inf = 1;
		if (data->f == -(1.0 / 0))
			data->is_neg = 1;
	}
}

void		edit_flag(t_data_struct *data)
{
	if (float_nan(data) || float_inf(data))
		edit_flag2(data);
	data->precision_width > 18 ? data->precision_width = 18 : 0;
	data->minus ? data->zero = 0 : 0;
	data->plus ? data->space = 0 : 0;
	if (!data->precision)
	{
		data->precision = 1;
		data->precision_width = 6;
	}
}

long double	number_characteristic(int pow)
{
	long double f;

	f = 1;
	while (pow-- > 0)
		f *= 10;
	while (pow++ < 0)
		f /= 10;
	return (f);
}

int			is_not_even_str(char *str)
{
	return ((str[ft_strlen(str) - 1] - '0') % 2);
}
