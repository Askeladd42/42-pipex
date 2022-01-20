/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:48:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 15:01:44 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_verification(char *cmd)
{
	/* using access to the command used to see if it exists : return OK if it
	** exists, ERR if it isn't.
	*/
	int ret;

	ret = access(cmd, X_OK);
	if (ret == -1)
		perror("cmd_line : ");
	return (ret);
}
