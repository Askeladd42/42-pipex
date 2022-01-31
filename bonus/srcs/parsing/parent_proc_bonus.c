/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:36 by plam              #+#    #+#             */
/*   Updated: 2022/01/31 15:50:47 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process(char **av, char **envp, t_ppx *ppx)
{
	int		fileout;

	fileout = open_file(av[4], OUTFILE);
	if (dup2(ppx->pipe[W_END], STDIN_FILENO) == ERR)
		perror("dup2 error :");
	close(ppx->pipe[R_END]);
	if (dup2(fileout, STDOUT_FILENO) == ERR)
		perror("dup2 error :");
	cmd_exec(av[3], envp, ppx);
}