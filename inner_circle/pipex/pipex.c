/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:28 by siyang            #+#    #+#             */
/*   Updated: 2023/01/26 13:50:17 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		infile;
	int		status;
	char	**args;
	char	*path;
	char	*bin;

	// exception

	// infile valid check
	if (access(argv[1], F_OK | R_OF) == -1)
		return (1);
	infile = open(argv[1], O_RDONLY);
	dup2(infile, STDIN_FILENO);

	// generate pipe
	if (pipe(fd) == -1)
		return (1);

	// generate child process
	pid = fork();
	if (pid == -1)
		return(1);

	//(if) child process
	else if (!pid)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		args = ft_split(argv[2], ' ');
		bin = find_bin(args[0], envp);
		path = ft_strjoin(bin, args[0]);
		execve(path, args, envp);
	}

	//(if) parent process
	else if (pid)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(pid, &status, 0);
		args = ft_split(argv[3], ' ');
		bin = find_bin(args[0], envp);
		path = ft_strjoin(bin, args[0]);
		execve(path, args, envp);
	}
}

char	*find_bin(char *arg, char **envp)
{

}
