/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:48:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 12:20:42 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* using access to the command used to see if it exists : return 0 if it
** exists, -1 if it isn't.
*/

void	dup2_verif(int fd1, int fd2, char **cmd, t_ppx *ppx)
{
	if (dup2(fd1, fd2) == -1)
		ex_perror(cmd, "dup2 error", 1, ppx);
}

int	cmd_verification(char *cmd)
{
	int	ret;

	ret = access(cmd, X_OK);
	if (ret == -1)
		perror("cmd line : ");
	return (ret);
}
