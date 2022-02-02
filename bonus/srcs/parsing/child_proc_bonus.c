/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 20:21:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *av, char **envp, t_ppx *ppx)
{
	pid_t	pid;

	printf("infile = %d \t pipe[0] = %d \t pipe[1] = %d\n", ppx->infile, ppx->pipe[0], ppx->pipe[1]);
	if (pipe(ppx->pipe) == ERR)
		perror("Pipe error ");
	printf("pipe[0] = %d \t pipe[1] = %d\n", ppx->pipe[0], ppx->pipe[1]);
	if (ppx->infile == -1)
	{
		pid = 0;
		ppx->infile = 0;
		close(ppx->pipe[R_END]);
	}
	else
		pid = fork();
	printf("infile = %d \t pipe[0] = %d \t pipe[1] = %d\n", ppx->infile, ppx->pipe[0], ppx->pipe[1]);
	if (pid == -1)
		fork_err(ppx);
	if (pid == 0)
	{
		if (dup2(ppx->pipe[R_END], STDOUT_FILENO) == ERR)
			perror("dup2 error ");
		close(ppx->pipe[R_END]);
		cmd_exec(av, envp, ppx);
	}
	else
	{
		if (dup2(ppx->pipe[W_END], STDIN_FILENO) == ERR)
			perror("dup2 error ");
		close(ppx->pipe[R_END]);
		waitpid(pid, NULL, 0);
		close(ppx->pipe[W_END]);
	}
}
