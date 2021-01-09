/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:59:17 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 22:59:18 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_p(va_list next_argument, t_data_struct *data)
{
	data->sharp = 1;
	data->l_count = 1;
	data->h_count = 0;
	data->plus = 0;
	data->space = 0;
	size_uint(next_argument, data);
	if (!data->u)
		data->flag_p = 2;
	else
		data->flag_p = 1;
	data->conversion_type = 'x';
	to_x(next_argument, data);
}
