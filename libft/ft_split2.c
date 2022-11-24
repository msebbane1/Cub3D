/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:46:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 13:28:12 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_is_charset2(char *str, char c, int i)
{
	if (i > 0)
	{
		if (str[i] == c && str[i - 1] != ',' && str[i + 1] != ',')
			return (0);
	}
	else
		if (str[i] == c && str[i + 1] != ',')
			return (0);
	return (1);
}

int	ft_count_word2(char *str, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && !ft_is_charset2(str, c, i))
			i++;
		if (str[i] && ft_is_charset2(str, c, i))
		{
			word++;
			while (str[i] && ft_is_charset2(str, c, i))
				i++;
		}
	}
	return (word);
}

char	*ft_malloc2(char *str, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i] && ft_is_charset2(str, c, i))
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (str[++i] && ft_is_charset2(str, c, i))
		tab[i] = str[i];
	tab[i] = '\0';
	return (tab);
}

char	**ft_split2(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = ft_count_word2(str, c);
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[j])
	{
		while (str[j] && !ft_is_charset2(str, c, j))
			j++;
		if (str[j] && ft_is_charset2(str, c, j))
		{
			tab[i] = ft_malloc2((str + j), c);
			i++;
			while (str[j] && ft_is_charset2(str, c, j))
				j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}