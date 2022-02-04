/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/04 19:08:32 by plam             ###   ########.fr       */
=======
/*   Updated: 2022/02/04 17:07:32 by plam             ###   ########.fr       */
>>>>>>> af1b392d7ca4cdc6756b121c3e6731bd2998f920
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
