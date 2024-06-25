/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:29:46 by cluby             #+#    #+#             */
/*   Updated: 2024/04/23 23:12:12 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(const char *s, char c)
{
	int		i;
	size_t	count;

	if (!s)
		return (0);
	if (c == '\0')
	{
		if (*s == '\0')
			return (0);
		else
			return (1);
	}
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

static void	*doit(char **str, const char *s, char c)
{
	int		i;
	int		j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			str[j] = ft_substr(s, start, i - start);
			if (!str[j])
			{
				freesplit(str);
				return (NULL);
			}
			j++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;

	words = countwords(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!doit(str, s, c))
		return (NULL);
	str[words] = NULL;
	return (str);
}
