/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 13:44:35 by plam             ###   ########.fr       */
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
		perror("Fork error ");
	if (pid == 0)
	{
		close(ppx->pipe[R_END]);
		if (dup2(ppx->pipe[1], STDOUT_FILENO) == ERR)
			perror("dup2 error ");
		cmd_exec(av, envp, ppx);
	}
	else
	{
		close(ppx->pipe[W_END]);
		if (dup2(R_END, STDIN_FILENO) == ERR)
			perror("dup2 error ");
		waitpid(pid, NULL, 0);
	}
}
