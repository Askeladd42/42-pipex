/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/02/03 10:49:41 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process(t_ppx *ppx, pid_t pid)
{
	if (dup2(ppx->pipe[W_END], STDIN_FILENO) == ERR)
		perror("dup2 error ");
	close(ppx->pipe[R_END]);
	waitpid(pid, NULL, 0);
	close(ppx->pipe[W_END]);
}

void	child_process(char *av, char **envp, t_ppx *ppx, int can_exec)
{
	pid_t	pid;

	if (pipe(ppx->pipe) == ERR)
		perror("Pipe error ");
	pid = fork();
	if (pid == -1)
		fork_err(ppx);
	if (pid == 0)
	{
		if (can_exec > 0)
		{
			if (dup2(ppx->pipe[R_END], STDOUT_FILENO) == ERR)
				perror("dup2 error ");
			close(ppx->pipe[R_END]);
			cmd_exec(av, envp, ppx);
		}
		exit_ppx(ppx);
	}
	else
		parent_process(ppx, pid);
}
