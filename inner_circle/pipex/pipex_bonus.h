/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:35 by siyang            #+#    #+#             */
/*   Updated: 2023/02/01 17:33:15 by siyang           ###   ########.fr       */
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

# define PARENT 0
# define CHILD 1

char	*find_bin(char *arg, char **envp);
void	execute_command(int *fd, char **argv, char **envp, int process);
void	exit_process(char *str);

#endif
