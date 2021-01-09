/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:54:44 by hcloves           #+#    #+#             */
/*   Updated: 2019/09/25 12:27:39 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptrdst;
	unsigned char *ptrsrc;
	unsigned char cc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	cc = (unsigned char)c;
	while (n--)
	{
		*ptrdst++ = *ptrsrc++;
		if (*(ptrdst - 1) == cc)
			return (ptrdst);
	}
	return (NULL);
}
