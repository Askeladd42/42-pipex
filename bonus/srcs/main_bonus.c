/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 17:06:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_open(int ac, t_ppx ppx, int infile, int outfile)
{
	infile = open_file(ppx.av[1], 2);
	outfile = open_file(ppx.av[ac - 1], 3);
}

int	main(int ac, char **av, char **envp)
{
	t_ppx	ppx;
	int		i;
	int		infile;
	int		outfile;

	init_ppx(&ppx, ac, av, envp);
	if (ppx.ac >= 5)
	{
		i = 2;
		infile = open_file(ppx.av[1], 2);
		outfile = open_file(ppx.av[ac - 1], 3);
		dup2(infile, STDIN_FILENO);
		while (ppx.cmd_cnt != 1)
		{
			child_process(av[i++], envp, &ppx);
			ppx.cmd_cnt--;
		}
		dup2(outfile, STDOUT_FILENO);
		cmd_exec(av[ac - 2], envp, &ppx);
	}
	else
		arg_err();
	free_ppx(&ppx);
	return (0);
}
