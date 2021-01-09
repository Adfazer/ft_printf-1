/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:45:55 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/02 16:36:33 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			size;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if ((!s1 || !s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(*res) * (size + 2))))
	{
		ft_strdel(&res);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
