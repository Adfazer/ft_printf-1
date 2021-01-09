/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:16:46 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 22:16:50 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_float(char **left_str, char **right_str)
{
	free(*left_str);
	free(*right_str);
}

int		free_str(t_data_struct *data, char **str)
{
	if (data->conversion_type == 'o' && data->sharp == 1)
		return (0);
	if (data->conversion_type == 'd' || data->conversion_type == 'i')
		return (free_str_i(data, &(*str)));
	else
	{
		if (data->u == 0 && data->precision && data->precision_width == 0
			&& !data->width && data->flag_p != 2)
		{
			free(*str);
			return (1);
		}
		if (data->u == 0 && data->precision && data->precision_width == 0)
		{
			free(*str);
			*str = ft_strdup(" ");
			data->flag_p == 2 ? data->len-- : 0;
		}
	}
	return (0);
}

void	strlen_and_zero_noliked(char **str, t_data_struct *data)
{
	data->len = ft_strlen(*str);
	*str = zero_precision(*str, data);
	data->len = ft_strlen(*str);
}

int		float_nan(t_data_struct *data)
{
	return (!(data->f == data->f));
}

int		float_inf(t_data_struct *data)
{
	if (data->f == (1.0 / 0.0) || data->f == -(1.0 / 0.0))
		return (1);
	return (0);
}
