/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:00:33 by siyang            #+#    #+#             */
/*   Updated: 2023/02/20 17:13:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_deque *a, t_deque *b)
{
	int	cnt[a->size][6];

	partitioning(a, b);
	while (b->size)
	{
		count_rotate_rrotate(cnt, a, b);
		optimal_selection(cnt, a, b);
	}
	rearrange(a);
}

void	partitioning(t_deque *a, t_deque *b)
{
	int	pivot[2];
	int	size;
	int	i;

	pivot[0] = a->size / 3;
	pivot[1] = pivot[0] * 2;
	i = 0;
	size = a->size;
	while (i < size)
	{
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
		i++;
	}
	while (a->size)
		push(a, b);
}

void	count_rotate_rrotate(int (*cnt)[6], t_deque *a, t_deque *b)
{
	t_node	*temp;
	int		i;

	temp = b->top;
	i = 0;
	while (i < b->size)
	{
		count_ra_rra(cnt[i], a, temp);
		if (i <= b->size / 2)
		{
			cnt[i][RB] = i;
			cnt[i][RRB] = 0;
		}
		else
		{
			cnt[i][RRB] = b->size - i;
			cnt[i][RB] = 0;
		}
		if (cnt[i][RA] > cnt[i][RB])
			cnt[i][RR] = cnt[i][RB];
		else
			cnt[i][RR] = cnt[i][RA];
		cnt[i][RA] -= cnt[i][RR];
		cnt[i][RB] -= cnt[i][RR];
		if (cnt[i][RRA] > cnt[i][RRB])
			cnt[i][RRR] = cnt[i][RRB];
		else
			cnt[i][RRR] = cnt[i][RRA];
		cnt[i][RRA] -= cnt[i][RRR];
		cnt[i][RRB] -= cnt[i][RRR];
		temp = temp->next;
		i++;
	}
}

void	count_ra_rra(int *cnt, t_deque *a, t_node *b)
{
	t_node	*prev;
	t_node	*next;
	int		i;

	prev = a->bottom;
	next = a->top;
	i = 0;
	while (i < a->size)
	{
		if (prev->value > next->value && (prev->value < b->value || b->value < next->value))
			break ;
		else if (prev->value < b->value && b->value < next->value)
			break ;
		prev = next;
		next = next->next;
		i++;
	}
	if (i <= a->size / 2)
	{
		cnt[RA] = i;
		cnt[RRA] = 0;
	}
	else
	{
		cnt[RRA] = a->size - i;
		cnt[RA] = 0;
	}
}

void	optimal_selection(int (*cnt)[6], t_deque *a, t_deque *b)
{
	int	index;
	int	num;
	int	i;

	// select less cnt
	i = 0;
	index = i;
	num = cnt[i][RA] + cnt[i][RRA] + cnt[i][RB] + cnt[i][RRB] + cnt[i][RR] + cnt[i][RRR];
	while (i < b->size)
	{
		if (num > cnt[i][RA] + cnt[i][RRA] + cnt[i][RB] + cnt[i][RRB] + cnt[i][RR] + cnt[i][RRR])
		{
			num = cnt[i][RA] + cnt[i][RRA] + cnt[i][RB] + cnt[i][RRB] + cnt[i][RR] + cnt[i][RRR];
			index = i;
		}
		i++;
	}

	while (cnt[index][RR] > 0)
	{
		rotate(a, b);
		cnt[index][RR]--;
	}
	while (cnt[index][RRR] > 0)
	{
		rrotate(a, b);
		cnt[index][RRR]--;
	}
	while (cnt[index][RA] > 0)
	{
		rotate(a, NULL);
		cnt[index][RA]--;
	}
	while (cnt[index][RRA] > 0)
	{
		rrotate(a, NULL);
		cnt[index][RRA]--;
	}
	while (cnt[index][RB] > 0)
	{
		rotate(NULL, b);
		cnt[index][RB]--;
	}
	while (cnt[index][RRB] > 0)
	{
		rrotate(NULL, b);
		cnt[index][RRB]--;
	}
	push(b, a);
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


