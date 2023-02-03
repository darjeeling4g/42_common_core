/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:56:16 by siyang            #+#    #+#             */
/*   Updated: 2023/02/03 15:00:10 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_process(char *str)
{
	if (str == NULL)
		exit(EXIT_SUCCESS);
	else if (str)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

void	execute_command(char *argv, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(argv, ' ');
	path = find_bin(args[0], envp);
	if (access(path, F_OK) == -1)
		exit_process("command cannot found");
	else if (access(path, X_OK) == -1)
		exit_process("permission denied");
	execve(path, args, envp);
}

char	*find_bin(char *arg, char **envp)
{
	int		i;
	char	**path_group;
	char	*path;
	char	*temp;

	while (ft_strnstr(*envp, "PATH", 4) == 0)
		envp++;
	path_group = ft_split(*envp + 5, ':');
	i = 0;
	while (path_group[i])
	{
		temp = ft_strjoin(path_group[i], "/");
		path = ft_strjoin(temp, arg);
		if (access(path, F_OK) == 0)
			break ;
		free(temp);
		free(path);
		i++;
	}
	i = -1;
	while (path_group[++i])
		free(path_group[i]);
	free(path_group);
	return (path);
}

void	child_process(int *pipeA, int *pipeB, int num)
{
	if (num == EVEN)
	{
		dup2(pipeB[1], STDOUT_FILENO);
		close(pipeB[0]);
	}
	else if (num == ODD)
	{
		dup2(pipeA[1], STDOUT_FILENO);
		close(pipeA[0]);
	}
}

void	parent_process(int *pipeA, int *pipeB, int num)
{
	if (num == EVEN)
	{
		dup2(pipeB[0], STDIN_FILENO);
		close(pipeB[1]);
		if (pipeA[0] > -1)
			close(pipeA[0]);
	}
	else if (num == ODD)
	{
		dup2(pipeA[0], STDIN_FILENO);
		close(pipeA[1]);
		if (pipeB[0] > -1)
			close(pipeB[0]);
	}
}
