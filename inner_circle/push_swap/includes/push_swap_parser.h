/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:54:03 by siyang            #+#    #+#             */
/*   Updated: 2023/02/25 22:11:35 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PARSER_H
# define PUSH_SWAP_PARSER_H

# include "libft.h"

// push_swap_parser.c
int		stack_parser(int argc, char **argv, int **arr);
char	*combine_args(int argc, char **argv);
void	is_integer(char **value_group);
void	is_duplicated(char **value_group);
int		*atoi_only_int_range(char **value_group);

// push_swap_utils.c
void	exit_process(int i);

#endif
