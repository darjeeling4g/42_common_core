/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:41 by siyang            #+#    #+#             */
/*   Updated: 2023/02/26 15:14:46 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deque)
{
	t_node	*a;
	t_node	*b;

	if (deque->size < 2)
		return ;
	a = pop_top(deque);
	b = pop_top(deque);
	push_top(deque, a);
	push_top(deque, b);
	ft_printf("s%c\n", deque->name);
}

void	push(t_deque *src, t_deque *dst)
{
	t_node	*temp;

	if (src->top == NULL)
		return ;
	temp = pop_top(src);
	push_top(dst, temp);
	ft_printf("p%c\n", dst->name);
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
	if (a && b)
		ft_printf("rr\n");
	else if (a)
		ft_printf("r%c\n", a->name);
	else if (b)
		ft_printf("r%c\n", b->name);
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
	if (a && b)
		ft_printf("rrr\n");
	else if (a)
		ft_printf("rr%c\n", a->name);
	else if (b)
		ft_printf("rr%c\n", b->name);
}
