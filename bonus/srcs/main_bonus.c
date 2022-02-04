/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/02/04 20:24:08 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	init_open(int ac, t_ppx *ppx)
{
	ppx->infile = open_file(ppx->av[1], 2);
	ppx->outfile = open_file(ppx->av[ac - 1], 3);
	if (ppx->infile == -1)
		return (0);
	return (1);
}

void	last_cmd(t_ppx ppx, int ac, char **av, char **envp)
{
	if (av[ac - 2][0] != '\0' && av[ac - 2][0] != ' ')
		cmd_exec(av[ac - 2], envp, &ppx);
	else
		error("command not found : ", av[ac - 2]);
}

int	main(int ac, char **av, char **envp)
{
	t_ppx	ppx;
	int		i;
	int		infile_open;

	init_ppx(&ppx, ac, av, envp);
	if (ppx.ac >= 5)
	{
		i = 2;
		infile_open = init_open(ac, &ppx);
		dup2(ppx.infile, STDIN_FILENO);
		while (ppx.cmd_cnt != 1)
		{
			child_process(av[i++], envp, &ppx, infile_open);
			ppx.cmd_cnt--;
			infile_open = 1;
		}
		dup2(ppx.outfile, STDOUT_FILENO);
		last_cmd(ppx, ac, av, envp);
	}
	else
		arg_err();
	free_ppx(&ppx);
	return (0);
}
