/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:28 by siyang            #+#    #+#             */
/*   Updated: 2023/02/02 22:24:44 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;
	int		file;

	p.pid = -1;
	p.a[0] = -1;
	p.a[1] = -1;
	p.b[0] = -1;
	p.b[1] = -1;
	p.i = infile_stdin(argc, argv, &file);
	multiple_pipe(argc, argv, envp, p);
	stdout_outfile(argc, argv, &file);
	execute_command(argv[argc - 2], envp);
}

void	multiple_pipe(int argc, char **argv, char **envp, t_pipe p)
{
	while (p.i < argc - 4)
	{
		if (p.i % 2)
			if (pipe(p.a) == -1)
				exit_process("pipe failure");
		if (!(p.i % 2))
			if (pipe(p.b) == -1)
				exit_process("pipe failure");
		p.pid = fork();
		if (p.pid == -1)
			exit_process("fork failure");
		else if (!p.pid)
		{
			child_process(p.a, p.b, p.i % 2);
			execute_command(argv[p.i + 2], envp);
		}
		else if (p.pid)
		{
			if (waitpid(p.pid, NULL, WNOHANG) == -1)
				exit_process("child process error");
			parent_process(p.a, p.b, p.i % 2);
		}
		p.i++;
	}
}

void	stdout_outfile(int argc, char **argv, int *file)
{
	close(*file);
	if (!(ft_strncmp(argv[1], "here_doc", 8)))
	{
		unlink(argv[1]);
		*file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
		*file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*file < 0)
		exit_process("file open failure");
	dup2(*file, STDOUT_FILENO);
}

void	creat_here_doc(char *filename, char *limiter)
{
	int		fd;
	int		len;
	int		limiter_len;
	char	*str;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_process("file open failure");
	limiter_len = ft_strlen(limiter);
	ft_printf("heredoc> ");
	str = get_next_line(0);
	while (str)
	{
		len = ft_strlen(str) - 1;
		if (len < limiter_len)
			len = limiter_len;
		if (!(ft_strncmp(str, limiter, len)))
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
		ft_printf("heredoc> ");
		str = get_next_line(0);
	}
	free(str);
	close(fd);
}

int	infile_stdin(int argc, char **argv, int *file)
{
	int	is_here_doc;

	if (!(ft_strncmp(argv[1], "here_doc", 8)))
	{
		if (argc < 6)
			exit_process("Wrong arguments");
		creat_here_doc(argv[1], argv[2]);
		is_here_doc = 1;
	}
	else
	{
		if (argc < 5)
			exit_process("Wrong arguments");
		if (access(argv[1], F_OK | R_OK) == -1)
			exit_process("Invalid infile");
		is_here_doc = 0;
	}
	*file = open(argv[1], O_RDONLY);
	if (*file < 0)
		exit_process("file open failure");
	dup2(*file, STDIN_FILENO);
	return (is_here_doc);
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
