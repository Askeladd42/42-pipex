/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 23:32:01 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, char **envp, t_ppx *ppx)
{
	int		filein;

	filein = open_file(av[1], INFILE);
	dup2(ppx->pipe[W_END], STDOUT_FILENO);
	close(ppx->pipe[W_END]);
	dup2(filein, STDIN_FILENO);
	close(ppx->pipe[R_END]);
	cmd_exec(av[2], envp);
}
