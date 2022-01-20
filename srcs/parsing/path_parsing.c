/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:01 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 14:46:34 by plam             ###   ########.fr       */
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

	PATH_from_envp = ft_substr(ppx->envp);
	mypaths = ft_split(PATH_from_envp, ":"); // see section 4 for a small note[0]
	mycmdargs = ft_split(ppx->av[2], " ");// in your child or parent processint  i;
	i = -1;
	while (mypaths[++i])
	{
		cmd = ft_strjoin(mypaths[i], ppx->av[2]); // protect your ft_join
		execve(cmd, mycmdargs, ppx->envp); // if execve succeeds, it exits
		// perror("Error"); <- add perror to debug
		free(cmd); // if execve fails, we free and we try a new path
	}
	return (EXIT_FAILURE);
}
