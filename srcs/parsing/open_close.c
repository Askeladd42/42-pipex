/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:13:43 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 13:30:40 by plam             ###   ########.fr       */
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
	ppx->outfile = open(ppx->av[ppx->ac - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ppx->outfile == -1)
		return (perror);
	if (ppx->infile == -1)
		return (perror); //change the perror with the right function	
	return (0);
}
