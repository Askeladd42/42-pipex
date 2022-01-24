/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 12:37:39 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int f1, char *cmd1)
{
	if (f1 < 0)		//protection if dup2() < 0
		return (ERR);
	else
		dup2(f1, STDIN_FILENO);
	//dup(end[1], STDOUT_FILENO); to put in pipex to confirm
	//close(end[0]); always close the unused pipes ! (avoid having other pipes open to make them finish their process)
	close(f1);
}

void	child_process(char **argv, char **envp, t_ppx *pip)
{
	int		filein;

	filein = open_file(argv[1], 2);
	dup2(pip->p[WRITE_END], STDOUT_FILENO);
	close(pip->p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(pip->p[READ_END]);
	exec(argv[2], envp);
}