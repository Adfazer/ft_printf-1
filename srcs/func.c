/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:38:33 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:46:54 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_sign(t_data_struct *data)
{
	if (data->n < 0)
	{
		print_other(data, "-", 1);
		data->len--;
	}
	else if ((data->plus && (data->n >= 0)) && data->conversion_type != 'u')
	{
		print_other(data, "+", 1);
		data->len--;
	}
	else if (data->space && !data->plus && (data->n >= 0) \
					&& data->conversion_type != 'u')
	{
		print_other(data, " ", 1);
		data->len--;
	}
}

void	prefix(t_data_struct *data)
{
	if (data->conversion_type == 'x')
	{
		print_other(data, "0x", 2);
		data->len -= 2;
	}
	if (data->conversion_type == 'X')
	{
		print_other(data, "0X", 2);
		data->len -= 2;
	}
	if (data->conversion_type == 'o')
	{
		print_other(data, "0", 1);
		data->len--;
	}
}

void	output_print(char *str, char *gaps, t_data_struct *data)
{
	if (data->is_int && data->zero)
		write_sign(data);
	if (data->sharp && data->u && data->zero && \
				data->precision_width < data->len)
		prefix(data);
	if (gaps && !data->minus)
		print_other(data, gaps, data->gaps_len);
	if (data->sharp && data->u && !data->zero && \
				data->precision_width < data->len)
		prefix(data);
	if (data->flag_p >= 1 && !data->u)
		prefix(data);
	if (data->is_int && !data->zero)
		write_sign(data);
	print_other(data, str, data->len);
	if (gaps && data->minus)
		print_other(data, gaps, data->gaps_len);
	free(str);
	free(gaps);
}

char	*print_gaps(t_data_struct *data)
{
	char	*str;
	int		i;
	char	zero_gaps;

	i = -1;
	if (data->width < data->len)
		return (NULL);
	if (!(str = ft_calloc((data->width - data->len + 1), sizeof(char))))
		return (NULL);
	if (data->precision && data->precision_width > data->len &&\
	data->conversion_type != 's' && data->conversion_type != 'c' &&\
	data->conversion_type != '%')
		data->zero = 0;
	if (data->zero)
		zero_gaps = '0';
	else
		zero_gaps = ' ';
	while (++i < data->width - data->len)
		str[i] = zero_gaps;
	data->gaps_len = i;
	str[i] = '\0';
	return (str);
}

char	*zero_precision(char *str, t_data_struct *data)
{
	int		i;
	int		j;
	char	*trash;

	i = -1;
	j = -1;
	if (!data->precision)
		return (str);
	if (data->precision_width < data->len)
		return (str);
	if (!(trash = ft_calloc(data->precision_width + data->len + 1, \
								sizeof(char))))
		return (NULL);
	while (++i < data->precision_width - data->len)
		trash[i] = '0';
	while (str[++j])
		trash[i + j] = str[j];
	trash[i + j] = '\0';
	free(str);
	return (trash);
}
