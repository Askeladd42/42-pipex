/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 00:25:09 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		pid1;
	t_ppx	ppx;

	if (ac == 5)
	{
		init_ppx(ppx, ac, av, envp);
		if (pipe(ppx.pipe) == -1)
			error("error with pipe", "");
		pid1 = fork();
		if (pid1 == -1)
			error("error with Fork", "");
		if (pid1 == 0)
			child_process(av, envp, &ppx);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, &ppx) ;
	}
	else
		arg_error(0);
	return (0);
}
