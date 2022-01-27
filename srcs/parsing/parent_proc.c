/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:36 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 23:32:09 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **av, char **envp, t_ppx *ppx)
{
	int		fileout;

	fileout = open_file(av[4], OUTFILE);
	dup2(ppx->pipe[R_END], STDIN_FILENO);
	close(ppx->pipe[R_END]);
	dup2(fileout, STDOUT_FILENO);
	close(ppx->pipe[W_END]);
	cmd_exec(av[3], envp);
}