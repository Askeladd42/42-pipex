/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:52 by plam              #+#    #+#             */
/*   Updated: 2022/01/14 16:58:30 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int f1, char *cmd1)
{
	if (f1 < 0)		//protection if dup2() < 0
		return (ERR);
	else
		dup2(f1, STDIN_FILENO);
	//dup(end[1], STDOUT_FILENO); to put in pipex to confirm
	//close(end[0]); always close the unused pipes ! (avoid having other pipes open to make them finish their process)
	close(f1);
}
