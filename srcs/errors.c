/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/24 13:17:22 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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