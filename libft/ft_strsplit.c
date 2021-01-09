/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:25:52 by hcloves           #+#    #+#             */
/*   Updated: 2019/09/27 12:59:18 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (count);
}

static char		*ft_getsword(char *word, char c)
{
	char	*strt;
	size_t	i;

	i = 0;
	strt = word;
	while (word[i] && word[i] != c)
		i++;
	word[i] = '\0';
	return (ft_strdup(strt));
}

static void		ft_wordsfree(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(words);
}

static char		**ft_getsword2(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_getsword(s, c)))
				{
					ft_wordsfree(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*str;

	if (!s || !(str = ft_strdup((char *)s)))
		return (NULL);
	words = ft_getsword2(str, c, ft_wordcount(str, c));
	free(str);
	return (words);
}
