/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:28 by siyang            #+#    #+#             */
/*   Updated: 2023/02/01 17:32:52 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (argc != 5)
		exit_process("Wrong arguments");
	if (access(argv[1], F_OK | R_OK) == -1)
		exit_process("Invalid infile");
	if (pipe(fd) == -1)
		exit_process("pipe failure");
	pid = fork();
	if (pid == -1)
		exit_process("fork failure");
	else if (!pid)
		execute_command(fd, argv, envp, CHILD);
	else if (pid)
	{
		waitpid(pid, &status, 0);
		execute_command(fd, argv, envp, PARENT);
	}
}

void	execute_command(int *fd, char **argv, char **envp, int process)
{
	int		file;
	char	**args;
	char	*path;

	if (process == CHILD)
		file = open(argv[1], O_RDONLY);
	else if (process == PARENT)
		file = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file < 0)
		exit_process("file open failure");
	close(fd[1 - process]);
	dup2(file, 1 - process);
	dup2(fd[0 + process], 0 + process);
	if (process == CHILD)
		args = ft_split(argv[2], ' ');
	else if (process == PARENT)
		args = ft_split(argv[3], ' ');
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
		printf("%s\n", path);
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
