/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:36:41 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/02 16:46:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	if (!(str = malloc(size + 1)))
	{
		ft_strdel(&str);
		return (NULL);
	}
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
