/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:13:43 by plam              #+#    #+#             */
/*   Updated: 2022/01/28 10:55:11 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_file(t_ppx *ppx)
{
	close(ppx->infile);
	close(ppx->outfile);
	return (0);
}

int	exit_ppx(t_ppx *ppx)
{
	close_file(ppx);
	return (0);
}

int	open_file(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == INFILE)
		fd = open(file, O_RDONLY, 0777);
	else if (type == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT| O_TRUNC, 0777);
	if (fd == -1)
		error("Can't open a file", "");
	return (fd);
}
