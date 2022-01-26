/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:34 by plam              #+#    #+#             */
/*   Updated: 2022/01/26 00:58:14 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <stdio.h>

# define ERR -1
# define IN 0
# define OUT 1

typedef struct pipex
{
	int		ac;
	char	**av;
	char	**envp;
	int		**pipe;
	int		infile;
	int		outfile;
	int		cmd_cnt;
}				t_ppx;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		open_file(t_ppx *ppx);
int		close_file(t_ppx *ppx);
int		init_ppx(t_ppx *ppx, int ac, char **av, char **envp);
void	free_ppx(t_ppx *ppx);
void	exit_perror(char *error, int code);
void	ex_perror(char **cmd, char *error, int code, t_ppx *ppx);
void	error(char *s, char *argv);
char	*path(char *cmd, char **envp);

int		cmd_verification(char *cmd);
int		cmd_exec(t_ppx *ppx, char *cmd);

int		child_process(int f1, char *cmd1);
int		parent_process(int f2, char *cmd2);

void	pipex(int f1, int f2, char *cmd1, char *cmd2);

#endif
