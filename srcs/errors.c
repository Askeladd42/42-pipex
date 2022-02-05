/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/02/05 15:14:28 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *s, char *av)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	arg_err(void)
{
	ft_putstr_fd("arg error\n", 2);
	exit(0);
}
