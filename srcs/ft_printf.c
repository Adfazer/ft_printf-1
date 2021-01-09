/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:48:40 by hcloves           #+#    #+#             */
/*   Updated: 2020/08/01 20:28:00 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_other(t_data_struct *data, char *str, int len)
{
	int		i;

	i = -1;
	data->ret += len;
	while (++i < len)
		write(1, &str[i], 1);
}

void	print_easy_str(t_data_struct *data, char *str)
{
	int		len;

	len = 0;
	while (str[data->i] && str[data->i] != '%')
	{
		write(1, &str[data->i], 1);
		len++;
		data->i++;
	}
	data->ret += len;
	data->i--;
}

int		ft_printf(const char *str, ...)
{
	t_data_struct	data;
	va_list			next_argument;

	ft_bzero(&data, sizeof(data));
	va_start(next_argument, str);
	while (str[data.i])
	{
		if (str[data.i] == '%' && str[data.i])
		{
			if (correct_character(str[data.i + 1]))
				parse((char*)str, next_argument, &data);
		}
		else if (str[data.i] && str[data.i] != '%')
			print_easy_str(&data, (char*)str);
		data.i++;
	}
	va_end(next_argument);
	return (data.ret);
}
