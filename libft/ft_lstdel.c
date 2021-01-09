/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:35:02 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/01 14:03:39 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *lstnext;

	if (alst && *alst)
	{
		while (*alst)
		{
			lstnext = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = lstnext;
		}
	}
}
