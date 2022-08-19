/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:17:24 by siyang            #+#    #+#             */
/*   Updated: 2022/08/19 14:12:16 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		lst = &new;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		if (new != NULL)
			new->next = NULL;
		ft_lstlast(*lst)->next = new;
	}
}
