/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:45:17 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 22:29:25 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include "push_swap_deque.h"
# include "push_swap_parser.h"

typedef enum e_cnt
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cnt;

// push_swap_bonus.c
void	checker(t_deque *a, t_deque *b);
int		check_instruction(char *inst, int len);
void	execute_instruction(int inst, t_deque *a, t_deque *b);
void	solution_check(t_deque *a, t_deque *b);

// push_swap_bonus_utils.c
void	swap(t_deque *a, t_deque *b);
void	push(t_deque *src, t_deque *dst);
void	rotate(t_deque *a, t_deque *b);
void	rrotate(t_deque *a, t_deque *b);
void	exit_process(int i);

#endif
