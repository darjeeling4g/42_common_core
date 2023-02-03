/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:35 by siyang            #+#    #+#             */
/*   Updated: 2023/02/03 14:59:53 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

# define PARENT 0
# define CHILD 1
# define EVEN 0
# define ODD 1

typedef struct s_pipe
{
	pid_t	pid;
	int		a[2];
	int		b[2];
	int		i;
}	t_pipe;

// pipex_bonus.c
int		infile_stdin(int argc, char **argv, int *file);
void	creat_here_doc(char *filename, char *limiter);
void	multiple_pipe(int argc, char **argv, char **envp, t_pipe pipe);
void	stdout_outfile(int argc, char **argv, int *file);

// pipex_utils_bonus.c
void	exit_process(char *str);
void	execute_command(char *argv, char **envp);
char	*find_bin(char *arg, char **envp);
void	child_process(int *pipeA, int *pipeB, int num);
void	parent_process(int *pipeA, int *pipeB, int num);

#endif
