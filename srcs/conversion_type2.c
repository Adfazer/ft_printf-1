/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:40:46 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:46:01 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	size_int(va_list next_argument, t_data_struct *data)
{
	if (data->l_count >= 2)
		data->n = (intmax_t)va_arg(next_argument, long long);
	else if (data->l_count == 1)
		data->n = (intmax_t)va_arg(next_argument, long);
	else if (data->h_count && ((data->h_count % 2) == 0))
		data->n = (intmax_t)((char)va_arg(next_argument, int));
	else if (data->h_count && ((data->h_count % 2) != 0))
		data->n = (intmax_t)((short)va_arg(next_argument, int));
	else
		data->n = (intmax_t)va_arg(next_argument, int);
}

void	size_uint(va_list next_argument, t_data_struct *data)
{
	if (data->l_count >= 2)
		data->u = (uintmax_t)va_arg(next_argument, unsigned long long);
	else if (data->l_count == 1)
		data->u = (uintmax_t)va_arg(next_argument, unsigned long);
	else if (data->h_count && ((data->h_count % 2) == 0))
		data->u = (uintmax_t)((unsigned char)va_arg(next_argument, int));
	else if (data->h_count && ((data->h_count % 2) != 0))
		data->u = (uintmax_t)((unsigned short)va_arg(next_argument, int));
	else
		data->u = (uintmax_t)va_arg(next_argument, unsigned int);
}

void	to_i_d(va_list next_argument, t_data_struct *data)
{
	char	*str;
	char	*gaps;

	data->is_int = 1;
	size_int(next_argument, data);
	str = itoa_intmax(data->n);
	data->len = intmax_len(data->n);
	str = zero_precision(str, data);
	data->len = ft_strlen(str);
	(data->n < 0) ? data->len++ : 0;
	(data->n >= 0) && (data->plus || data->space) ? data->len++ : 0;
	if (free_str(data, &str))
		return ;
	gaps = print_gaps(data);
	output_print(str, gaps, data);
}

char	*o_u_b_itoa(uintmax_t n, int system)
{
	char		*str;
	int			str_count;

	str_count = o_u_b_x_len(n, system);
	if (!(str = ft_calloc((str_count + 1), sizeof(char))))
		return (NULL);
	str[str_count] = '\0';
	while (str_count)
	{
		str[--str_count] = n % system + 48;
		n = n / system;
	}
	return (str);
}

void	to_o_u_b(va_list next_argument, t_data_struct *data)
{
	char	*str;
	char	*gaps;

	data->is_int = 1;
	size_uint(next_argument, data);
	if (data->conversion_type == 'o')
		str = o_u_b_itoa(data->u, 8);
	if (data->conversion_type == 'u')
		str = o_u_b_itoa(data->u, 10);
	if (data->conversion_type == 'b')
		str = o_u_b_itoa(data->u, 2);
	if (data->conversion_type == 't')
		str = o_u_b_itoa(data->u, 3);
	if (data->conversion_type == 'q')
		str = o_u_b_itoa(data->u, 4);
	strlen_and_zero_noliked(&str, data);
	if (free_str(data, &str))
		return ;
	data->sharp && data->u && data->precision_width < 2 ? data->len += 1 : 0;
	gaps = print_gaps(data);
	output_print(str, gaps, data);
}
