/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:00:06 by lbally            #+#    #+#             */
/*   Updated: 2022/12/05 18:18:15 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strdupp(const char *s1)
{
	void	*str;
	char	*a;
	size_t	i;

	str = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	a = (char *)str;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	remplace(t_cub *cub)
{
	char	*lolo;
	int		i;
	int		w;
	int		t;
	int		y;

	i = 0;
	w = 0;
	t = 0;
	y = cub->map.index_spaces;
	while (cub->map.str[y])
	{
		w = 0;
		while (cub->map.str[y][w])
			w++;
		if (i < w)
			i = w;
		y++;
		t++;
	}
	w = 0;
	cub->map.size.y = t + 1;
	cub->map.size.x = i + 1;
	cub->map.rmap = malloc(sizeof(char *) * (cub->map.size.y) + 1);
	cub->map.rmap[t] = NULL;
	lolo = malloc(sizeof(char) * (cub->map.size.x));
	t = 0;
	while (cub->map.rmap[t])
	{
		lolo[i] = '\0';
		cub->map.rmap[t] = ft_strdupp(lolo);
		t++;
	}
	t = 0;
	y = cub->map.index_spaces;
	while (cub->map.rmap[t])
	{
		w = 0;
		while (cub->map.str[y][w])
		{
			cub->map.rmap[t][w] = cub->map.str[y][w];
			if (cub->map.rmap[t][w] == ' ' || cub->map.rmap[t][w] == '\0'
				|| cub->map.rmap[t][w] == '\n')
				cub->map.rmap[t][w] = '1';
			w++;
		}
		if (w < i)
		{
			while (w < i)
			{
				cub->map.rmap[t][w] = '1';
				w++;
			}
		}
		printf("%s\n", cub->map.rmap[t]);
		t++;
		y++;
	}
}
