/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ppx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:18:50 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 23:52:07 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_ppx(t_ppx ppx, int ac, char **av, char **envp)
{
	ppx.ac = ac;
	ppx.av = av;
	ppx.envp = envp;
	ppx.cmd_cnt = ac - 3;
	ppx.infile = 0;
	ppx.outfile = 0;
	ppx.pipe[0] = 0;
	ppx.pipe[1] = 0;
	return (0);
}
