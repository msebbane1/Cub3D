/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:45:36 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 15:39:19 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_is_charset(const char *str, char c)
{
	int	i;

	i = 0;
	if (str[i] == c)
		return (0);
	return (1);
}

int	ft_count_word(const char *str, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && !ft_is_charset(&str[i], c))
			i++;
		if (str[i] && ft_is_charset(&str[i], c))
		{
			word++;
			while (str[i] && ft_is_charset(&str[i], c))
				i++;
		}
	}
	return (word);
}

char	*ft_malloc(const char *str, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i] && ft_is_charset(&str[i], c))
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (str[++i] && ft_is_charset(&str[i], c))
		tab[i] = str[i];
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = ft_count_word(str, c);
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[j])
	{
		while (str[j] && !ft_is_charset(&str[j], c))
			j++;
		if (str[j] && ft_is_charset(&str[j], c))
		{
			tab[i] = ft_malloc((str + j), c);
			i++;
			while (str[j] && ft_is_charset(&str[j], c))
				j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
