/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:29:05 by siyang            #+#    #+#             */
/*   Updated: 2022/08/19 15:04:53 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	while ((*lst)->next != NULL)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free(*lst);
		lst = &temp;
	}
	ft_lstdelone(*lst, del);
	lst = NULL;
}
