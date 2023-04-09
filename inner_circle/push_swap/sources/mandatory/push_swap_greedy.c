/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:00:33 by siyang            #+#    #+#             */
/*   Updated: 2023/02/23 21:03:41 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_deque *a, t_deque *b)
{
	int	(*cnt)[6];

	cnt = malloc(sizeof(int) * 6 * a->size);
	if (!(cnt))
		exit_process(1);
	partitioning(a, b);
	sort_under_three(a);
	while (b->size)
	{
		count_rotate_rrotate(cnt, a, b);
		execute_selection(cnt, a, b, optimal_selection(cnt, b));
	}
	free(cnt);
	rearrange(a);
}

void	sort_under_three(t_deque *a)
{
	int	value[3];

	if (a->size == 2 && (a->top->value > a->top->next->value))
		swap(a);
	else if (a->size == 3)
	{
		value[0] = a->top->value;
		value[1] = a->top->next->value;
		value[2] = a->top->next->next->value;
		if (value[0] < value[2])
		{
			if (value[0] < value[1] && value[1] > value[2])
				swap(a);
			else if (value[0] > value[1] && value[1] < value[2])
				swap(a);
		}
		else
			if (value[0] > value[1] && value[1] > value[2])
				swap(a);
	}
}

void	partitioning(t_deque *a, t_deque *b)
{
	int	pivot[2];
	int	size;
	int	i;

	pivot[0] = a->size / 3;
	pivot[1] = pivot[0] * 2;
	i = -1;
	size = a->size;
	while (++i < size)
	{
		if (a->size < 4)
			break ;
		if (a->top->value > pivot[0] && a->top->value <= pivot[1])
			push(a, b);
		else if (a->top->value <= pivot[0])
		{
			push(a, b);
			if (b->size > 1 && b->top->next->value > pivot[0])
				rotate(NULL, b);
		}
		else
			rotate(a, NULL);
	}
	while (a->size > 3)
		push(a, b);
}

void	rearrange(t_deque *a)
{
	t_node	*temp;
	int		i;

	temp = a->top;
	i = 0;
	while (temp->value)
	{
		temp = temp->next;
		i++;
	}
	while (a->top->value)
	{
		if (i <= a->size / 2)
			rotate(a, NULL);
		else
			rrotate(a, NULL);
	}
}
