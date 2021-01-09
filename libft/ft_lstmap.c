/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:54:35 by hcloves           #+#    #+#             */
/*   Updated: 2019/10/01 16:24:25 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	new = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
		{
			while (new)
			{
				free(new->content);
				free(new);
				new = new->next;
			}
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (new);
}
