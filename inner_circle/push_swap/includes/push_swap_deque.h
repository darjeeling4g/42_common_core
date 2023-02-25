/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:02:38 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 22:11:38 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEQUE_H
# define PUSH_SWAP_DEQUE_H

# include <stdlib.h>

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

// push_swap_deque.c
void	deque_generator(t_deque *a, int *arr);
t_node	*new_node(int value);
void	node_add_back(t_node **top, t_node *new);

// push_swap_deque_utils.c
void	push_top(t_deque *deque, t_node *new);
void	push_bottom(t_deque *deque, t_node *new);
t_node	*pop_top(t_deque *deque);
t_node	*pop_bottom(t_deque *deque);

// push_swap_utils.c
void	exit_process(int i);

#endif
