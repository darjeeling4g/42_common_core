/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:59:36 by siyang            #+#    #+#             */
/*   Updated: 2022/08/31 17:22:09 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_map(void *content);
static void		ft_lstclear_map(t_list **lst, void (*del)(void*));
static void		ft_lstadd_back_map(t_list **lst, t_list *new);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new = ft_lstnew_map(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear_map(&start, del);
			return (NULL);
		}
		ft_lstadd_back_map(&start, new);
		lst = lst->next;
	}
	return (start);
}

static t_list	*ft_lstnew_map(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	ft_lstclear_map(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}

static void	ft_lstadd_back_map(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
