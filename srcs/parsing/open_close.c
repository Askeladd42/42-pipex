/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:13:43 by plam              #+#    #+#             */
/*   Updated: 2022/01/25 00:04:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_file(t_ppx *ppx)
{
	close(ppx->infile);
	close(ppx->outfile);
	return (0);
}


int	open_file(t_ppx *ppx)
{
	ppx->infile = open(ppx->av[1], O_RDONLY);
	if (ppx->infile == -1)
		ex_perror(ppx->av[ppx->ac - 1], ppx->infile);
	ppx->outfile = open(ppx->av[ppx->ac - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ppx->outfile == -1)
	{
		ft_putstr_fd("0\n", ppx->outfile);
		ex_perror(ppx->av[1], 0);
	}
	return (0);
}
