/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 18:29:48 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *av, char **envp, t_ppx *ppx)
{
	pid_t	pid;

	if (pipe(ppx->pipe) == ERR)
		perror("Pipe error ");
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error ");
		close(ppx->pipe[R_END]);
		exit(2);
	}
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
