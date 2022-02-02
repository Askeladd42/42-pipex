/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 19:23:25 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_err(t_ppx	*ppx)
{
	perror("Fork error ");
	close(ppx->pipe[R_END]);
	exit(2);
}

void	error(char *s, char *av)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	arg_err(void)
{
	ft_putstr_fd("arg error\n", 2);
	exit(0);
}
