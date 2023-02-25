/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:18 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 23:46:43 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	greedy(&a, &b);
}
