/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:39:58 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*m_list;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	m_list = NULL;
	while (lst)
	{
		c = f(lst->content);
		node = ft_lstnew(c);
		if (!node)
		{
			free(c);
			ft_lstclear(&m_list, *(del));
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&m_list, node);
		}
		lst = lst->next;
	}
	return (m_list);
}
