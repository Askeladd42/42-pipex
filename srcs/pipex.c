/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:04:23 by plam              #+#    #+#             */
/*   Updated: 2022/01/14 15:04:53 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	pid_t	prt;

	pipe(end);
	prt = fork();
	if (prt < 0)
		return (perror("Fork: "));
	if (!prt)
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
}
