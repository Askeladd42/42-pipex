/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ppx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:32:18 by plam              #+#    #+#             */
/*   Updated: 2022/01/31 15:50:12 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*fr_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

void	free_ppx(t_ppx *ppx)
{
	ppx->ac = 0;
	ppx->av = 0;
	ppx->envp = NULL;
	ppx->cmd_cnt = 0;
	ppx->infile = 0;
	ppx->outfile = 0;
	ppx->pipe[0] = 0;
	ppx->pipe[1] = 0;
}
