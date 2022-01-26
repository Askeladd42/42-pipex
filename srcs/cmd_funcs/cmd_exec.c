/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:36:18 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 12:05:04 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* temporary function */

int	cmd_exec(t_ppx *ppx, char *cmd, int index)
{
	pid_t	pid;

	pipe(ppx->pipe);
	pid = fork();
	if (pid == -1)
		ex_perror(cmd, index, 1, ppx);
	else if (pid == 0)
	{
		//create the conditions of the child process & execute them
	}
	waitpid(-1);
	return (pid);
}
