/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:36:18 by plam              #+#    #+#             */
/*   Updated: 2022/02/04 19:06:43 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char *av, char **envp, t_ppx *ppx)
{
	char	**cmd;
	char	*cmd_path;

	if (av == NULL || av[0] == '\0')
	{
		free_ppx(ppx);
		exit(0);
	}
	cmd = ft_split(av, ' ');
	cmd_path = path_parsing(cmd[0], envp);
	if (cmd_path == NULL)
	{
		access(cmd[0], X_OK);
		perror("command not found");
	}
	else
		execve(cmd_path, cmd, envp);
	if (cmd_path)
		free(cmd_path);
	fr_tab(cmd);
	free_ppx(ppx);
	error("command error : ", av);
}
