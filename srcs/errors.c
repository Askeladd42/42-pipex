/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 12:58:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error("open problem", "");
	return (file);
}

void	error(char *s, char *argv)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	arg_error(int err)
{
	ft_putstr("Arg error !");
	exit(0);
}
