/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:49:22 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 21:47:26 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remember_flag_mod(t_data_struct *data, char *str)
{
	if (str[data->i] == '.')
	{
		data->precision = 1;
		data->precision_parsing = 1;
		data->precision_width = 0;
	}
	str[data->i] == ' ' ? data->space = 1 : 0;
	str[data->i] == '+' ? data->plus = 1 : 0;
	str[data->i] == '#' ? data->sharp = 1 : 0;
	str[data->i] == 'l' ? data->l_count += 1 : 0;
	str[data->i] == 'h' ? data->h_count += 1 : 0;
	str[data->i] == 'L' ? data->lf_count = 1 : 0;
}

void	parse3(t_data_struct *data, char *c, char *str)
{
	c[0] = str[data->i + 1];
	c[1] = '\0';
	data->len = 1;
	data->minus ? print_other(data, c, 1) : 0;
}

int		parse2(char *str, va_list next_arg, t_data_struct *data)
{
	char	*gaps;
	char	*c;

	while (!correct_character2(str[data->i]))
	{
		check_prec_wid(str, next_arg, data);
		if (!str[data->i + 1])
			return (0);
		if (!correct_character(str[data->i + 1]))
		{
			c = ft_calloc(2, sizeof(char));
			parse3(data, c, str);
			gaps = print_gaps(data);
			print_other(data, gaps, data->gaps_len);
			!data->minus ? print_other(data, c, 1) : 0;
			free(c);
			free(gaps);
			data->i++;
			return (0);
		}
		data->i++;
	}
	return (1);
}

void	select_conv_type(va_list next_arg, t_data_struct *data, char *str)
{
	data->conversion_type = str[data->i];
	str[data->i] == 'c' ? to_c(next_arg, data) : 0;
	str[data->i] == 'd' || str[data->i] == 'i' ? to_i_d(next_arg, data) : 0;
	str[data->i] == 'o' || str[data->i] == 'u' ? to_o_u_b(next_arg, data) : 0;
	str[data->i] == 'b' || str[data->i] == 't' ? to_o_u_b(next_arg, data) : 0;
	str[data->i] == 'x' || str[data->i] == 'X' ? to_x(next_arg, data) : 0;
	str[data->i] == 'f' ? to_f(next_arg, data) : 0;
	str[data->i] == '%' ? to_c(next_arg, data) : 0;
	str[data->i] == 's' ? to_s(next_arg, data) : 0;
	str[data->i] == 'p' ? to_p(next_arg, data) : 0;
	str[data->i] == 'q' ? to_o_u_b(next_arg, data) : 0;
}

void	parse(char *str, va_list next_arg, t_data_struct *data)
{
	data->i++;
	data->flag_p = -1;
	ft_bzero(&(*data), ((sizeof(*data)) - 16));
	if (!parse2(str, next_arg, data))
		return ;
	if (data->width < 0)
	{
		data->minus = 1;
		data->zero = 0;
		data->width = -(data->width);
	}
	if (data->precision_width < 0)
		data->precision = 0;
	if (str[data->i] != 's' && str[data->i] != 'c' && str[data->i] != '%')
		data->precision && data->precision_width >= 0 ? data->zero = 0 : 0;
	select_conv_type(next_arg, data, str);
}
