/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/01/29 09:46:29 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	pid1;
	t_ppx	ppx;

	ppx.ac = ac;
	if (ac == 5)
	{
		init_ppx(&ppx, ac, av, envp);
		if (pipe(ppx.pipe) == -1)
			perror("pipe error :");
		pid1 = fork();
		if (pid1 == -1)
			perror("fork error :");
		if (pid1 == 0)
			child_process(av, envp, &ppx);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, &ppx);
	}
	else
		arg_err();
	free_ppx(&ppx);
	return (0);
}
