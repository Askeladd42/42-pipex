/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:34 by plam              #+#    #+#             */
/*   Updated: 2022/01/14 15:04:01 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

void	child_process(int f1, char *cmd1);
void	parent_process(int f2, char *cmd2);

void	pipex(int f1, int f2, char *cmd1, char *cmd2);

#endif
