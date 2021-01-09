/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:40:19 by hcloves           #+#    #+#             */
/*   Updated: 2020/07/31 22:40:21 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		size_float(va_list next_argument, t_data_struct *data)
{
	if (data->lf_count)
		data->f = (long double)va_arg(next_argument, long double);
	else
		data->f = (long double)va_arg(next_argument, double);
}

int			count_left_float(long double f)
{
	int count;

	count = 0;
	while (f > 1)
	{
		count++;
		f /= 10;
	}
	if (count > 1)
		return (count);
	return (1);
}

char		*left_float(long double f)
{
	char		*s;
	char		*ptr;
	int			count;
	int			i;
	long double	trash;

	count = count_left_float(f);
	if (!(s = (char*)ft_memalloc(count + 1)))
		return (NULL);
	ptr = s;
	while (count)
	{
		i = count - 1;
		trash = f;
		while (i--)
			trash /= 10;
		*ptr++ = (int)trash + '0';
		trash = (int)trash;
		while (++i < count - 1)
			trash *= 10;
		f -= trash;
		--count;
	}
	return (s);
}

char		*right_float(long double f, int p, char *left_float)
{
	int		i;
	char	*s;

	i = 0;
	f = f < 0 ? -f : f;
	f -= atoi_float(left_float);
	if (!(s = (char*)ft_memalloc(p + 1)))
	{
		free(s);
		return (NULL);
	}
	while (i < p)
	{
		f *= 10;
		s[i++] = (f > 0) ? (int)f + '0' : '0';
		f -= (int)f;
	}
	return (s);
}

long double	atoi_float(char *s)
{
	long double f;

	f = 0;
	while (*s)
	{
		f *= 10;
		f += (long double)(*s - '0');
		++s;
	}
	return (f);
}
