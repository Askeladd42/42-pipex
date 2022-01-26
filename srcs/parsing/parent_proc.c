/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:36 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 12:50:36 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//will change if not used maybe

/*int	parent_process(int f2, char *cmd2)
{
	int	status;
	waitpid(-1, &status, 0);	//waiting for the child to finish her process
	dup2(f2, ...);				//f2 = stdout
	dup2(end[0], ...);			//end[0] = stdin
	close(end[1]);
	close(f2);
}*/

void	parent_process(char **av, char **envp, t_ppx *ppx)
{
	int		fileout;

	fileout = open_file(ppx);
	dup2(ppx->pipe[READ_END], STDIN_FILENO);
	close(ppx->pipe[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(ppx->pipe[WRITE_END]);
	cmd_exec(av[3], envp);
}