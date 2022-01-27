/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:01 by plam              #+#    #+#             */
/*   Updated: 2022/01/27 23:47:26 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_parsing(char *path, char **envp)
{
	char	**PATH_from_envp;
	char	*my_path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	PATH_from_envp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (PATH_from_envp[i])
	{
		part_path = ft_strjoin(PATH_from_envp[i], "/");
		my_path = ft_strjoin(part_path, path);
		free(part_path);
		if (access(my_path, F_OK) == 0)
		{
			fr_tab(PATH_from_envp);
			return (my_path);
		}
		i++;
	}
	fr_tab(PATH_from_envp);
	return (NULL);
}
