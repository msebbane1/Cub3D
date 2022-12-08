/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:51:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/08 11:21:15 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = -1;
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s3 = malloc(len1 + len2 + 1)))
		return (0);
	else
	{
		while (s1[++i] != '\0')
			s3[i] = s1[i];
		i = -1;
		while (s2[++i] != '\0')
			s3[len1 + i] = s2[i];
	}
	s3[len1 + len2] = '\0';
	return (s3);
}

int	ft_char_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
}

int	ft_skip_format(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n' || line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
}

int	line_size_max(t_cub *cub)
{
	int		l;
	int		size_max;

	l = cub->map.index_spaces;
	size_max = 0;
	while (cub->map.str[l])
	{
		if (size_max < ft_strlen(cub->map.str[l]))
			size_max = ft_strlen(cub->map.str[l]);
		l++;
	}
	return (size_max);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int		check_characters_valid(t_cub *cub)
{
	int	l;
	int	c;

	l = 0;
	while (cub->map.str[l])
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			if (cub->map.str[l][c] != ' ' && cub->map.str[l][c] != '\t'
				&& cub->map.str[l][c] != '\r' && cub->map.str[l][c] != '\f'
				&& cub->map.str[l][c] != '\v')
				return (1);
			c++;
		}
		l++;
	}
	return (0);
}

int	check_params(char **str)
{
	int	i;

	i = 0;
	if (str[i])
		i++;
	//if (i > 2)
		//return (1);
	return (i);
}
