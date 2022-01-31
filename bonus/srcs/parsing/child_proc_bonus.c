/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/01/31 15:50:34 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char **av, char **envp, t_ppx *ppx)
{
	int		filein;

	filein = open_file(av[1], INFILE);
	if (dup2(ppx->pipe[R_END], STDOUT_FILENO) == ERR)
		perror("dup2 error :");
	close(ppx->pipe[W_END]);
	if (dup2(filein, STDIN_FILENO) == ERR)
		perror("dup2 error :");
	cmd_exec(av[2], envp, ppx);
}
