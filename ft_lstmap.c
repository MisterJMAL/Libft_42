/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:46 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/14 16:25:33 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*newelement;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newelement = ft_lstnew((*f)(lst->content));
		if (newelement == NULL)
		{
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, newelement);
		lst = lst->next;
	}
	return (newlst);
}
