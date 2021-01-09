/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:13:40 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/01 17:05:57 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*temp;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (!(temp = (char*)malloc(sizeof(*src) * (len + 1))))
	{
		ft_strdel(&temp);
		return (0);
	}
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
