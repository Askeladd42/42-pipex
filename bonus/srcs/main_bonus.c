/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/01/31 18:02:48 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_ppx	ppx;
	int		i;
	int		infile;
	int		outfile;

	i = 0;
	ppx.ac = ac;
	if (ac >= 5)
	{
		init_ppx(&ppx, ac, av, envp);
		i = 2;
		infile = open(ppx.av[1], 2);
		outfile = open_file(ppx.av[ac - 1], 1);
		dup2(infile, STDIN_FILENO);
		while (ppx.cmd_cnt != 1)
		{
			child_process(av[i++], envp, &ppx);
		}
		dup2(outfile, STDOUT_FILENO);
		cmd_exec(av[ac - 2], envp, &ppx);
	}
	else
		arg_err();
	free_ppx(&ppx);
	return (0);
}
