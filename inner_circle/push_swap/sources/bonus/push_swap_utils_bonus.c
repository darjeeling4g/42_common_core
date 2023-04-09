/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:59 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 23:59:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_deque *a, t_deque *b)
{
	t_node	*node[2];

	if (a)
	{
		if (a->size > 1)
		{
			node[0] = pop_top(a);
			node[1] = pop_top(a);
			push_top(a, node[0]);
			push_top(a, node[1]);
		}
	}
	if (b)
	{
		if (b->size > 1)
		{
			node[0] = pop_top(b);
			node[1] = pop_top(b);
			push_top(b, node[0]);
			push_top(b, node[1]);
		}
	}
}

void	push(t_deque *src, t_deque *dst)
{
	t_node	*temp;

	if (src->top == NULL)
		return ;
	temp = pop_top(src);
	push_top(dst, temp);
}

void	rotate(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (a)
	{
		if (a->size > 1)
		{
			temp = pop_top(a);
			push_bottom(a, temp);
		}
	}
	if (b)
	{
		if (b->size > 1)
		{
			temp = pop_top(b);
			push_bottom(b, temp);
		}
	}
}

void	rrotate(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (a)
	{
		if (a->size > 1)
		{
			temp = pop_bottom(a);
			push_top(a, temp);
		}
	}
	if (b)
	{
		if (b->size > 1)
		{
			temp = pop_bottom(b);
			push_top(b, temp);
		}
	}
}

void	exit_process(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	exit(i);
}
