/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:09 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 12:47:13 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int main(int ac, char **av, char **envp)
{
	int f1;
	int f2;

	if (ac > 2)
	{
		f1 = open(av[1], O_RDONLY);
		f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		pipex(f1, f2, av, envp);
	}
	return (0);
}
*/

int	main(int argc, char **argv, char **envp)
{
	int		pid1;
	t_ppx	pip;

	if (argc == 5)
	{
		init_pipex(pip, argc, argv, envp);
		if (pipe(pip.p) == -1)
			error("error with pipe", "");
		pid1 = fork();
		if (pid1 == -1)
			error("error with Fork", "");
		if (pid1 == 0)
			child_process(argv, envp, &pip);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, &pip);
	}
	else
		arg_error(0);
	return (0);
}
