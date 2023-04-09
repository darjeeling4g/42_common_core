/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:35:03 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 22:12:32 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_deque.h"

void	deque_generator(t_deque	*a, int *arr)
{
	t_node	*new;
	int		i;
	int		j;
	int		cnt;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		cnt = 0;
		while (j < a->size)
		{
			if (arr[i] > arr[j])
				cnt++;
			j++;
		}
		new = new_node(cnt);
		if (!(new))
			exit_process(1);
		node_add_back(&(a->top), new);
		a->bottom = new;
		i++;
	}
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!(new))
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	node_add_back(t_node **top, t_node *new)
{
	t_node	*last;

	if (top == NULL || new == NULL)
		return ;
	if (!(*top))
		*top = new;
	else
	{
		last = *top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
