/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:26:21 by plam              #+#    #+#             */
/*   Updated: 2022/01/20 16:30:14 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* temporay function for the outfile verification */

int	outfile_path(char *path)
{
	int	ret;

	ret = open(path, O_CREAT);
	return (ret);
}