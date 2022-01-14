/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:38:00 by plam              #+#    #+#             */
/*   Updated: 2021/01/07 08:41:51 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_prints(char const *s, char c)
{
	size_t	i;
	int		p;

	i = 0;
	p = 0;
	while (s && s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			p++;
		i++;
	}
	return (p);
}

static char	**free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	print_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	splitter(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s && s[k])
	{
		while (s[k] == c)
			k++;
		tab[i] = malloc(sizeof(char) * (print_len(&s[k], c) + 1));
		if (tab[i] == NULL)
			free_tab(tab);
		if (s[k])
		{
			j = 0;
			while (s[k] && s[k] != c)
				tab[i][j++] = s[k++];
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(*tab) * (count_prints(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	splitter(s, c, tab);
	return (tab);
}
