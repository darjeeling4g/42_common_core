/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:46:27 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 23:46:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	int		*arr;

	if (argc < 2)
		return (0);
	a.name = 'a';
	b.name = 'b';
	a.size = 0;
	b.size = 0;
	a.top = NULL;
	b.top = NULL;
	a.bottom = NULL;
	b.bottom = NULL;
	a.size = stack_parser(argc, argv, &arr);
	if (!(a.size))
		exit_process(1);
	deque_generator(&a, arr);
	free(arr);
	checker(&a, &b);
}

void	checker(t_deque *a, t_deque *b)
{
	char	*inst;
	int		len;

	inst = get_next_line(0);
	while (inst)
	{
		len = ft_strlen(inst) - 1;
		execute_instruction(check_instruction(inst, len), a, b);
		free(inst);
		inst = get_next_line(0);
	}
	solution_check(a, b);
}

int	check_instruction(char *inst, int len)
{
	if (len == 3 && !(ft_strncmp(inst, "rra", 3)))
		return (RRA);
	else if (len == 3 && !(ft_strncmp(inst, "rrb", 3)))
		return (RRB);
	else if (len == 3 && !(ft_strncmp(inst, "rrr", 3)))
		return (RRR);
	else if (len == 2 && !(ft_strncmp(inst, "sa", 2)))
		return (SA);
	else if (len == 2 && !(ft_strncmp(inst, "sb", 2)))
		return (SB);
	else if (len == 2 && !(ft_strncmp(inst, "ss", 2)))
		return (SS);
	else if (len == 2 && !(ft_strncmp(inst, "pa", 2)))
		return (PA);
	else if (len == 2 && !(ft_strncmp(inst, "pb", 2)))
		return (PB);
	else if (len == 2 && !(ft_strncmp(inst, "ra", 2)))
		return (RA);
	else if (len == 2 && !(ft_strncmp(inst, "rb", 2)))
		return (RB);
	else if (len == 2 && !(ft_strncmp(inst, "rr", 2)))
		return (RR);
	else
		return (-1);
}

void	execute_instruction(int inst, t_deque *a, t_deque *b)
{
	if (inst == SA)
		swap(a, NULL);
	else if (inst == SB)
		swap(NULL, b);
	else if (inst == SS)
		swap(a, b);
	else if (inst == PA)
		push(b, a);
	else if (inst == PB)
		push(a, b);
	else if (inst == RA)
		rotate(a, NULL);
	else if (inst == RB)
		rotate(NULL, b);
	else if (inst == RR)
		rotate(a, b);
	else if (inst == RRA)
		rrotate(a, NULL);
	else if (inst == RRB)
		rrotate(NULL, b);
	else if (inst == RRR)
		rrotate(a, b);
	else
		exit_process(1);
}

void	solution_check(t_deque *a, t_deque *b)
{
	t_node	*curr;
	t_node	*next;

	if (b->top)
	{
		write(1, "KO\n", 3);
		exit_process(0);
	}
	curr = a->top;
	next = curr->next;
	while (next)
	{
		if (curr->value > next->value)
		{
			write(1, "KO\n", 3);
			exit_process(0);
		}
		curr = next;
		next = curr->next;
	}
	write(1, "OK\n", 3);
	exit_process(0);
}
