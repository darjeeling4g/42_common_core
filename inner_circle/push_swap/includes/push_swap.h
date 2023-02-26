/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:12 by siyang            #+#    #+#             */
/*   Updated: 2023/02/26 15:16:14 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include "push_swap_deque.h"
# include "push_swap_parser.h"

typedef enum e_cnt
{
	RB,
	RRB,
	RA,
	RRA,
	RR,
	RRR
}	t_cnt;

// push_swap_utils.c
void	sorted_check(t_deque *a);
void	exit_process(int i);

// push_swap_utils.c
void	swap(t_deque *deque);
void	push(t_deque *src, t_deque *dst);
void	rotate(t_deque *a, t_deque *b);
void	rrotate(t_deque *a, t_deque *b);

// push_swap_greedy.c
void	greedy(t_deque *a, t_deque *b);
void	partitioning(t_deque *a, t_deque *b);
void	sort_under_three(t_deque *a);
void	rearrange(t_deque *a);

// push_swap_greedy_utils.c
void	count_rotate_rrotate(int (*cnt)[6], t_deque *a, t_deque *b);
void	count_ra_rra(int *cnt, t_deque *a, t_node *b);
void	count_rr_rrr(int *cnt);
int		optimal_selection(int (*cnt)[6], t_deque *b);
void	execute_selection(int (*cnt)[6], t_deque *a, t_deque *b, int i);

#endif
