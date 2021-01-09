/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:41:01 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:46:37 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(t_data_struct *data)
{
	char		*left_str;
	char		*right_str;
	long double	trash;

	data->f = data->f < 0 ? -data->f : data->f;
	trash = data->f * number_characteristic(data->precision_width);
	left_str = left_float(trash);
	right_str = right_float(trash, data->precision_width, left_str);
	trash -= atoi_float(left_str);
	free(left_str);
	free(right_str);
	if (trash > 0.5 || (trash == 0.5 && is_not_even_str(left_str)))
		data->f += 0.5 * number_characteristic(-(data->precision_width));
}

void	block_len_f(char *left_str, t_data_struct *data)
{
	if (data->is_inf || data->is_nan)
		data->ret = 3;
	else
		data->ret = ft_strlen(left_str) + data->precision_width;
	if (data->precision_width > 0 || data->sharp)
		data->ret += 1;
	if (data->space || data->plus)
		data->ret += 1;
}

void	write_padding(int len, char c)
{
	while (len)
	{
		write(1, &c, 1);
		--len;
	}
}

void	pad_block_f(t_data_struct *data, int flag)
{
	if (!data->zero && !data->minus && data->width >
		data->ret && flag == 1)
		write_padding(data->width - data->ret, ' ');
	else if (!data->zero && data->minus && data->width >
		data->ret && flag == 2)
		write_padding(data->width - data->ret, ' ');
	else if (flag == 0)
	{
		if (data->zero && data->width)
			write_padding(data->width > data->ret ? \
			data->width - data->ret : 0, '0');
	}
}

void	output_print_f(t_data_struct *data, char *left_str, char *right_str)
{
	block_len_f(left_str, data);
	pad_block_f(data, 1);
	if (data->space || data->plus || data->is_neg)
		write(1, &(data->is_sign), 1);
	pad_block_f(data, 0);
	write(1, left_str, ft_strlen(left_str));
	if (data->precision_width || data->sharp)
		write(1, ".", 1);
	write(1, right_str, ft_strlen(right_str));
	pad_block_f(data, 2);
}
