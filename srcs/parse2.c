/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:51:02 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:47:41 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		correct_character2(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' \
	|| c == 'X' || c == '%' || c == 'f' || c == 'c' \
	|| c == 's' || c == 'b' || c == 't' || c == 'p' || c == 'q')
		return (1);
	return (0);
}

int		correct_character(char c)
{
	if (correct_character2(c) || (c >= '0' && c <= '9')
	|| c == '-' || c == ' ' || c == '.' || c == '+' || c == '#' || c == '*'
	|| c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

void	check_prec_wid(char *str, va_list next_argument, t_data_struct *data)
{
	if (str[data->i] == '*')
	{
		if (data->precision_parsing)
			data->precision_width = va_arg(next_argument, int);
		else
			data->width = va_arg(next_argument, int);
	}
	if (str[data->i] == '0' && !data->minus && !data->precision_parsing)
		data->zero = 1;
	if (str[data->i] >= '1' && str[data->i] <= '9' && !data->precision_parsing)
		data->width = atoi_start_i(str, &data->i);
	if (str[data->i] >= '0' && str[data->i] <= '9' && data->precision_parsing)
		data->precision_width = atoi_start_i(str, &data->i);
	data->precision_parsing = 0;
	if (str[data->i] == '-')
	{
		data->zero = 0;
		data->minus = 1;
	}
	remember_flag_mod(data, str);
}

int		free_str_i(t_data_struct *data, char **str)
{
	if (data->n == 0 && data->precision && data->precision_width == 0
		&& !data->width)
	{
		free(*str);
		return (1);
	}
	if (data->n == 0 && data->precision && data->precision_width == 0)
	{
		free(*str);
		*str = ft_strdup(" ");
	}
	return (0);
}

void	fixer_condition(char *str, int number, t_data_struct *data, int neg)
{
	if ((str[18] - 48) >= 8)
	{
		number = 10 - (str[19] - 48);
		if (neg)
			long_double_fixer_neg(data, number);
		else
			long_double_fixer_plus(data, number);
	}
}
