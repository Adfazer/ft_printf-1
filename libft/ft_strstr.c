/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:39:15 by hcloves           #+#    #+#             */
/*   Updated: 2019/09/25 23:53:06 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	if (*needle == '\0')
		return ((char*)haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + j);
		}
		j++;
	}
	return (NULL);
}
