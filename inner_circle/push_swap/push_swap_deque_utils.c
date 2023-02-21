/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:33:11 by siyang            #+#    #+#             */
/*   Updated: 2023/02/21 16:06:57 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_deque *deque, t_node *new)
{
	if (deque->top == NULL)
	{
		deque->top = new;
		deque->bottom = new;
		deque->size = 1;
	}
	else
	{
		new->prev = NULL;
		new->next = deque->top;
		deque->top->prev = new;
		deque->top = new;
		deque->size++;
	}
}

void	push_bottom(t_deque *deque, t_node *new)
{
	if (deque->top == NULL)
	{
		deque->top = new;
		deque->bottom = new;
		deque->size = 1;
	}
	else
	{
		new->prev = deque->bottom;
		new->next = NULL;
		deque->bottom->next = new;
		deque->bottom = new;
		deque->size++;
	}
}

t_node	*pop_top(t_deque *deque)
{
	t_node	*res;

	res = deque->top;
	deque->top = deque->top->next;
	if (deque->top)
		deque->top->prev = NULL;
	res->prev = NULL;
	res->next = NULL;
	deque->size--;
	return (res);
}

t_node	*pop_bottom(t_deque *deque)
{
	t_node	*res;

	res = deque->bottom;
	deque->bottom = deque->bottom->prev;
	if (deque->top)
		deque->bottom->next = NULL;
	res->prev = NULL;
	res->next = NULL;
	deque->size--;
	return (res);
}
