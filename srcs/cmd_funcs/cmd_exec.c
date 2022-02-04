/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:36:18 by plam              #+#    #+#             */
/*   Updated: 2022/02/04 11:59:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char *av, char **envp, t_ppx *ppx)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(av, ' ');
	cmd_path = path_parsing(cmd[0], envp);
	if (cmd_path == NULL)
		execve(cmd[0], cmd, envp);
	else
		execve(cmd_path, cmd, envp);
	if (cmd_path)
		free(cmd_path);
	fr_tab(cmd);
	free_ppx(ppx);
	error("command error : ", av);
}
