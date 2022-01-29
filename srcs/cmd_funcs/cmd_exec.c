/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:36:18 by plam              #+#    #+#             */
/*   Updated: 2022/01/29 09:45:16 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* temporary function */

void	cmd_exec(char *av, char **envp, t_ppx *ppx)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (execve(path_parsing(cmd[0], envp), cmd, envp) == -1)
	{
		fr_tab(cmd);
		free_ppx(ppx);
		error("command error : ", av);
	}
	fr_tab(cmd);
}
