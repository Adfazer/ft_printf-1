/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:40:31 by hcloves           #+#    #+#             */
/*   Updated: 2020/08/04 20:44:07 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_s(va_list next_argument, t_data_struct *data)
{
	char	*str;
	char	*gaps;

	if (data->precision && data->precision_width < 0)
		data->precision_width = -data->precision_width;
	if (!(str = (char *)va_arg(next_argument, char *)))
		str = strdup_l("(null)", data);
	else
		str = strdup_l(str, data);
	data->len = ft_strlen(str);
	gaps = print_gaps(data);
	output_print(str, gaps, data);
}

void	to_c(va_list next_argument, t_data_struct *data)
{
	char	*str;
	char	*gaps;

	data->len = 1;
	if (data->conversion_type == 'c')
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = (char)va_arg(next_argument, int);
		str[1] = '\0';
	}
	if (data->conversion_type == '%')
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '%';
		str[1] = '\0';
	}
	gaps = print_gaps(data);
	output_print(str, gaps, data);
}

char	*itoa_x_xx(uintmax_t n, char *str_16form)
{
	char	*str;
	int		count_str;
	int		system;

	count_str = o_u_b_x_len(n, 16);
	system = ft_strlen(str_16form);
	if (!(str = ft_calloc((count_str + 1), sizeof(char))))
		return (NULL);
	str[count_str] = '\0';
	while (count_str)
	{
		str[--count_str] = str_16form[n % system];
		n = n / system;
	}
	return (str);
}

void	to_x(va_list next_argument, t_data_struct *data)
{
	char	*str;
	char	*gaps;

	data->is_int = 1;
	data->flag_p < 1 ? size_uint(next_argument, data) : 0;
	if (data->conversion_type == 'x')
		str = itoa_x_xx(data->u, "0123456789abcdef");
	if (data->conversion_type == 'X')
		str = itoa_x_xx(data->u, "0123456789ABCDEF");
	strlen_and_zero_noliked(&str, data);
	if (free_str(data, &str))
		return ;
	data->sharp && data->u ? data->len += 2 : 0;
	data->flag_p == 2 ? data->len += 2 : 0;
	gaps = print_gaps(data);
	output_print(str, gaps, data);
}
