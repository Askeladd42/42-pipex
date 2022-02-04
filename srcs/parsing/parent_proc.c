/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:36 by plam              #+#    #+#             */
/*   Updated: 2022/02/04 19:45:06 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **av, char **envp, t_ppx *ppx)
{
	int		fileout;

	fileout = open_file(av[4], OUTFILE);
	if (dup2(ppx->pipe[W_END], STDIN_FILENO) == ERR)
		perror("dup2 error :");
	close(ppx->pipe[R_END]);
	if (dup2(fileout, STDOUT_FILENO) == ERR)
		perror("dup2 error :");
	if (av[3][0] != '\0' && av[3][0] != ' ')
		cmd_exec(av[3], envp, ppx);
}
