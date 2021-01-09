/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:59:17 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 22:59:18 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signe_f(t_data_struct *data)
{
	data->is_sign = data->space ? ' ' : '+';
	if (data->f < 0)
	{
		data->is_sign = '-';
		data->is_neg = 1;
	}
}

void	long_double_fixer_plus(t_data_struct *data, int number)
{
	number == 10 ? data->f += 0.0000000000000000011 : 0;
	number == 9 ? data->f += 0.00000000000000000091 : 0;
	number == 8 ? data->f += 0.00000000000000000081 : 0;
	number == 7 ? data->f += 0.00000000000000000071 : 0;
	number == 6 ? data->f += 0.00000000000000000061 : 0;
	number == 5 ? data->f += 0.00000000000000000051 : 0;
	number == 4 ? data->f += 0.00000000000000000041 : 0;
	number == 3 ? data->f += 0.00000000000000000031 : 0;
	number == 2 ? data->f += 0.00000000000000000021 : 0;
	number == 1 ? data->f += 0.00000000000000000011 : 0;
}

void	long_double_fixer_neg(t_data_struct *data, int number)
{
	number == 10 ? data->f -= 0.0000000000000000011 : 0;
	number == 9 ? data->f -= 0.00000000000000000091 : 0;
	number == 8 ? data->f -= 0.00000000000000000081 : 0;
	number == 7 ? data->f -= 0.00000000000000000071 : 0;
	number == 6 ? data->f -= 0.00000000000000000061 : 0;
	number == 5 ? data->f -= 0.00000000000000000051 : 0;
	number == 4 ? data->f -= 0.00000000000000000041 : 0;
	number == 3 ? data->f -= 0.00000000000000000031 : 0;
	number == 2 ? data->f -= 0.00000000000000000021 : 0;
	number == 1 ? data->f -= 0.00000000000000000011 : 0;
}

void	long_double_fixer(t_data_struct *data)
{
	long double			trash_f;
	char				*str;
	char				*sub_str;
	int					number;
	int					neg;

	number = 0;
	neg = 0;
	if (data->lf_count)
	{
		trash_f = data->f;
		if (trash_f < 0)
		{
			trash_f = -(trash_f);
			neg = 1;
		}
		sub_str = left_float(trash_f);
		str = right_float(trash_f, 20, sub_str);
		fixer_condition(str, number, data, neg);
		free(sub_str);
		free(str);
	}
}

void	to_f(va_list next_argument, t_data_struct *data)
{
	char			*left_str;
	char			*right_str;

	size_float(next_argument, data);
	edit_flag(data);
	signe_f(data);
	if (!data->is_inf && !data->is_nan)
	{
		long_double_fixer(data);
		rounding(data);
		left_str = left_float(data->f);
		right_str = right_float(data->f, data->precision_width, left_str);
	}
	else
	{
		left_str = data->is_inf ? "inf" : "nan";
		right_str = "";
	}
	output_print_f(data, left_str, right_str);
	if (!data->is_inf && !data->is_nan)
		free_float(&left_str, &right_str);
}
