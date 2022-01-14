/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:01 by plam              #+#    #+#             */
/*   Updated: 2022/01/14 16:08:28 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_parsing(char *path)
{
	char *PATH_from_envp;
	char **mypaths;
	char **mycmdargs;// retrieve the line PATH from envp
	PATH_from_envp = ft_substr(envp ....);
	mypaths = ft_split(PATH_from_envp, ":"); // see section 4 for a small note[0]
	mycmdargs = ft_split(ag[2], " ");// in your child or parent processint  i;
	char *cmd;i = -1;
	while (mypaths[++i])
	{
		cmd = ft_join(mypaths[i], ag[2]); // protect your ft_join
		execve(cmd, mycmdargs, envp); // if execve succeeds, it exits
		// perror("Error"); <- add perror to debug
		free(cmd) // if execve fails, we free and we try a new path
	}
	return (EXIT_FAILURE);
}