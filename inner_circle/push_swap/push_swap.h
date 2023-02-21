/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:12 by siyang            #+#    #+#             */
/*   Updated: 2023/02/21 15:46:02 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef enum e_cnt
{
	RB,
	RRB,
	RA,
	RRA,
	RR,
	RRR
}	t_cnt;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	char			name;
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_deque;

// push_swap_utils.c
void	swap(t_deque *deque);
void	push(t_deque *src, t_deque *dst);
void	rotate(t_deque *a, t_deque *b);
void	rrotate(t_deque *a, t_deque *b);
void	exit_process(int i);

// push_swap_parser.c
int		stack_parser(int argc, char **argv, int **arr);
char	*combine_args(int argc, char **argv);
void	is_integer(char **value_group);
void	is_duplicated(char **value_group);
int		*atoi_only_int_range(char **value_group);

// push_swap_deque.c
void	deque_generator(t_deque *a, int *arr);
t_node	*new_node(int value);
void	node_add_back(t_node **top, t_node *new);

// push_swap_deque_utils.c
void	push_top(t_deque *deque, t_node *new);
void	push_bottom(t_deque *deque, t_node *new);
t_node	*pop_top(t_deque *deque);
t_node	*pop_bottom(t_deque *deque);

// greedy
void	greedy(t_deque *a, t_deque *b);
void	partitioning(t_deque *a, t_deque *b);
void	count_rotate_rrotate(int (*cnt)[6], t_deque *a, t_deque *b);
void	count_ra_rra(int *cnt, t_deque *a, t_node *b);
void	optimal_selection(int (*cnt)[6], t_deque *a, t_deque *b);
void	rearrange(t_deque *a);

#endif
