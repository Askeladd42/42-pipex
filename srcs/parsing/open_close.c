/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:13:43 by plam              #+#    #+#             */
/*   Updated: 2022/02/05 15:11:08 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_pipe(t_ppx *ppx)
{
	close(ppx->pipe[W_END]);
	close(ppx->pipe[R_END]);
	free_ppx(ppx);
	return (0);
}

int	exit_ppx(t_ppx *ppx, int errno)
{
	close_pipe(ppx);
	exit(errno);
}

int	open_file(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == INFILE)
		fd = open(file, O_RDONLY, 0777);
	else if (type == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error("Can't open the file : ", file);
	return (fd);
}
