/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ppx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:32:18 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 12:34:41 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_tab(char **tab)
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
	ppx->pipe = NULL;
}
