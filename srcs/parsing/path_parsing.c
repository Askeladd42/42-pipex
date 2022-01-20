/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:01 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 15:41:21 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* must use access(path, F_OK) to see if the outfile exist:
** if not, use open(path, O_CREAT).
*/

int	path_parsing(char *path, t_ppx *ppx)
{
	char *PATH_from_envp;
	char **mypaths;
	char **mycmdargs;// retrieve the line PATH from envp
	char *cmd;
	int i;

	PATH_from_envp = ft_substr(ppx->envp, "infile"); //temporary, not sure about this one
	mypaths = ft_split(PATH_from_envp, ":");
	mycmdargs = ft_split(ppx->av[2], " ");// in your child or parent process;
	i = -1;
	while (mypaths[++i])
	{
		cmd = ft_strjoin(mypaths[i], ppx->av[2]); // protect your ft_strjoin
		execve(cmd, mycmdargs, ppx->envp); // if execve succeeds, it exits -> cmd_exec
		// perror("Error"); <- add perror to debug
		free(cmd); // if execve fails, we free and we try a new path
	}
	return (EXIT_FAILURE);
}
