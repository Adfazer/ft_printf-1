/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:35:42 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/02 16:23:40 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_revstr(size_t i, size_t len, char *ptrs, char const *s)
{
	size_t temp;

	temp = 0;
	while (i <= len && s[i])
	{
		ptrs[temp] = s[i];
		i++;
		temp++;
	}
	ptrs[temp] = '\0';
	return (ptrs);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	char	*ptrs;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		ptrs = ft_memalloc(1);
		ptrs[0] = '\0';
		return (ptrs);
	}
	len--;
	while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
		len--;
	if (!(ptrs = (char *)malloc(sizeof(char) * (len - i) + 1)))
	{
		ft_strdel(&ptrs);
		return (NULL);
	}
	return (ft_revstr(i, len, ptrs, s));
}
