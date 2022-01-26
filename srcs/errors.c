/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:03 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 12:24:13 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_perror(char *error, int code)
{
	perror(error);
	exit(code);
}

void	ex_perror(char **cmd, char *error, int code, t_ppx *ppx)
{
	ft_strlcpy(ppx->err_str, cmd, ft_strlen(*cmd) + 1);			//à corriger
	exit_ppx();													//à créer
	exit_perror(error, code);
}
