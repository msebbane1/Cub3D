/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:00:06 by lbally            #+#    #+#             */
/*   Updated: 2022/11/28 17:51:26 by lbally           ###   ########.fr       */
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
	cub->map.str = malloc(sizeof(char *) * (cub->map.size.y));
	cub->map.str[t] = NULL;
	lolo = malloc(sizeof(char) * (cub->map.size.x));
	printf("TATATAT ======= %d\n", t);
	y = 0;
	while (y <= t)
	{
		lolo[i] = '\0';
		cub->map.str[t] = ft_strdupp(lolo);
		y++;
	}
	t = 0;
	y = cub->map.index_spaces;
	while (cub->map.str[t])
	{
		w = 0;
		while (cub->map.str[y][w])
		{
			cub->map.str[t][w] = cub->map.str[y][w];
			if (cub->map.str[t][w] == ' ' || cub->map.str[t][w] == '\0'
				|| cub->map.str[t][w] == '\n')
				cub->map.str[t][w] = '1';
			w++;
		}
		if (w < i)
		{
			while (w < i)
			{
				cub->map.str[t][w] = '1';
				w++;
			}
		}
		printf("%s\n", cub->map.str[t]);
		printf("TTTTT ===== %d\n", t);
		t++;
		y++;
	}
}
