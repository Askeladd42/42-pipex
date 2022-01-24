/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:13:43 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 13:16:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_file(int file)
{
	close(file);
	return (0);
}


int	open_file(t_ppx *ppx)
{
	int	file;

	file = 0;
	if (i == 1)
		file = open(ppx->av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(ppx->av, O_RDONLY, 0777);
	if (file == -1)
		error("open problem", "");
	return (file);
}
