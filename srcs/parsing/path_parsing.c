/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:01 by plam              #+#    #+#             */
/*   Updated: 2022/01/29 09:43:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_parsing(char *path, char **envp)
{
	char	**path_from_envp;
	char	*my_path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_from_envp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_from_envp[i])
	{
		part_path = ft_strjoin(path_from_envp[i], "/");
		my_path = ft_strjoin(part_path, path);
		free(part_path);
		if (access(my_path, F_OK) == 0)
		{
			fr_tab(path_from_envp);
			return (my_path);
		}
		i++;
	}
	fr_tab(path_from_envp);
	free(my_path);
	return (NULL);
}
