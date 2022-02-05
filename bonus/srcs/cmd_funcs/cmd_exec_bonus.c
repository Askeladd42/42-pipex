/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:36:18 by plam              #+#    #+#             */
/*   Updated: 2022/02/05 00:58:28 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd_exec(char *av, char **envp, t_ppx *ppx)
{
	char	**cmd;
	char	*cmd_path;

	if (av[0] == ' ' || av[0] == '\0')
	{
		free_ppx(ppx);
		error("command not found : ", av);
	}
	cmd = ft_split(av, ' ');
	cmd_path = path_parsing(cmd[0], envp);
	if (cmd_path == NULL)
	{
		if (execve(cmd[0], cmd, envp) == ERR)
			close(ppx->pipe[R_END]);
	}
	else
	{
		if (execve(cmd_path, cmd, envp) == ERR)
			close(ppx->pipe[R_END]);
	}
	if (cmd_path)
		free(cmd_path);
	fr_tab(cmd);
	free_ppx(ppx);
	error("command not found : ", av);
}
