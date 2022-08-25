/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:59:36 by siyang            #+#    #+#             */
/*   Updated: 2022/08/25 16:28:34 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	start = new;
	lst = lst->next;
	while (lst && start)
	{
		new = ft_lstnew(f(lst->content));
		ft_lstadd_back(&start, new);
		if (new == NULL)
		{
			ft_lstclear(&start, del);
			start = NULL;
			break ;
		}
		lst = lst->next;
	}
	return (start);
}
