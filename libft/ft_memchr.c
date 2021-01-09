/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:02:01 by hcloves           #+#    #+#             */
/*   Updated: 2019/09/25 12:28:27 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptrs;

	ptrs = (unsigned char*)s;
	while (n--)
	{
		if (*ptrs == (unsigned char)c)
			return (ptrs);
		ptrs++;
	}
	return (NULL);
}
