/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 23:56:29 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *s, char *av)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	arg_err(void)
{
	ft_putstr_fd("arg error", 2);
	exit(0);
}
