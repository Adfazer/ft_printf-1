/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:22:21 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/02 14:52:04 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s)
		return (NULL);
	if (!(res = ft_memalloc(len + 1)))
	{
		ft_strdel(&res);
		return (NULL);
	}
	res = ft_strncpy(res, (char*)s + start, len);
	return (res);
}
