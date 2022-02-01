/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:01:46 by plam              #+#    #+#             */
/*   Updated: 2022/02/02 00:11:33 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <stdio.h>

# define ERR -1
# define W_END 0
# define R_END 1

# define INFILE 2
# define OUTFILE 3

typedef struct pipex
{
	int		ac;
	char	**av;
	char	**envp;
	int		pipe[2];
	int		infile;
	int		outfile;
	int		cmd_cnt;
}				t_ppx;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

int		open_file(char *file, int type);
int		init_ppx(t_ppx *ppx, int ac, char **av, char **envp);
void	free_ppx(t_ppx *ppx);
void	*fr_tab(char **tab);

void	arg_err(void);
void	error(char *s, char *av);

char	*path_parsing(char *path, char **envp);
void	cmd_exec(char *av, char **envp, t_ppx *ppx);

void	child_process(char *av, char **envp, t_ppx *ppx);

#endif
