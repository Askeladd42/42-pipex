/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:48:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 15:38:09 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* using access to the command used to see if it exists : return 0 if it
** exists, -1 if it isn't.
*/

int	cmd_verification(char *cmd)
{
	int	ret;

	ret = access(cmd, X_OK);
	if (ret == -1)
		perror("cmd line : ");
	return (ret);
}
