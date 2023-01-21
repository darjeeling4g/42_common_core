/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:14:28 by siyang            #+#    #+#             */
/*   Updated: 2023/01/21 13:26:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	pipe[2];

	//exception

	//parse infile

	//generate pipe
	if (pipe(pipe) == -1)
		return (1);

	//generate child process

	//(if) child process
	//

	//(if) parent process
	// waitpid

	//
}
