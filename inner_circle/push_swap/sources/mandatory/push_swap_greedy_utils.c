/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:15:32 by siyang            #+#    #+#             */
/*   Updated: 2023/03/01 15:31:41 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		count_rr_rrr(cnt[i]);
		temp = temp->next;
		i++;
	}
}

void	count_ra_rra(int *cnt, t_deque *a, t_node *b)
{
	t_node	*p;
	t_node	*n;
	int		i;

	p = a->bottom;
	n = a->top;
	i = 0;
	while (i < a->size)
	{
		if (p->value > n->value && (p->value < b->value || b->value < n->value))
			break ;
		else if (p->value < b->value && b->value < n->value)
			break ;
		p = n;
		n = n->next;
		i++;
	}
	if (i <= a->size / 2)
		cnt[RA] = i;
	else
		cnt[RRA] = a->size - i;
	if (i <= a->size / 2)
		cnt[RRA] = 0;
	else
		cnt[RA] = 0;
}

void	count_rr_rrr(int *cnt)
{
	if (cnt[RA] > cnt[RB])
		cnt[RR] = cnt[RB];
	else
		cnt[RR] = cnt[RA];
	cnt[RA] -= cnt[RR];
	cnt[RB] -= cnt[RR];
	if (cnt[RRA] > cnt[RRB])
		cnt[RRR] = cnt[RRB];
	else
		cnt[RRR] = cnt[RRA];
	cnt[RRA] -= cnt[RRR];
	cnt[RRB] -= cnt[RRR];
}

int	optimal_selection(int (*cnt)[6], t_deque *b)
{
	int	res;
	int	num;
	int	i;

	i = 0;
	res = i;
	num = cnt[i][RA] + cnt[i][RB] + cnt[i][RR]
		+ cnt[i][RRA] + cnt[i][RRB] + cnt[i][RRR];
	while (i < b->size)
	{
		if (num > cnt[i][RA] + cnt[i][RB] + cnt[i][RR]
				+ cnt[i][RRA] + cnt[i][RRB] + cnt[i][RRR])
		{
			num = cnt[i][RA] + cnt[i][RB] + cnt[i][RR]
				+ cnt[i][RRA] + cnt[i][RRB] + cnt[i][RRR];
			res = i;
		}
		i++;
	}
	return (res);
}

void	execute_selection(int (*cnt)[6], t_deque *a, t_deque *b, int i)
{
	while (cnt[i][RR]-- > 0)
		rotate(a, b);
	while (cnt[i][RRR]-- > 0)
		rrotate(a, b);
	while (cnt[i][RA]-- > 0)
		rotate(a, NULL);
	while (cnt[i][RRA]-- > 0)
		rrotate(a, NULL);
	while (cnt[i][RB]-- > 0)
		rotate(NULL, b);
	while (cnt[i][RRB]-- > 0)
		rrotate(NULL, b);
	push(b, a);
}
