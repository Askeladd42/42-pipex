/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:04:23 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 12:45:25 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	pid_t	ch1;
	pid_t	ch2;

	pipe(end);
	ch1 = fork();
	if (ch1 < 0)
		return (perror("Fork: "));
	if (!ch1)
		child_process(f1, cmd1);
	ch2 = fork();
	if (ch2 < 0)
		return (perror("Fork: "));
	if (!ch2)
		child_process(f2, cmd2);
	close(end[0]);
	close(end[1]);
	waitpid(ch1, &status, 0);
	waitpid(ch2, &status, 0);
}
