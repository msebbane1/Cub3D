/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:51:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 16:59:19 by lbally           ###   ########.fr       */
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
	s3 = malloc(len1 + len2 + 1);
	if (!s3)
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

int	ft_skip_format(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n' || line[i] == '\t' || line[i] == ' ')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O'
			&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		|| (line[i] == 'S' && line[i + 1] == 'O'
			&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		|| (line[i] == 'W' && line[i + 1] == 'E'
			&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		|| (line[i] == 'E' && line[i + 1] == 'A'
			&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		|| (line[i] == 'F' && (line[i + 1] == ' '
				|| line[i + 1] == '\t')) || (line[i] == 'C'
			&& (line[i + 1] == ' ' || line[i + 1] == '\t')) || line[i] == '\0')
		return (1);
	return (0);
}

void	ft_trim_format(t_cub *cub, char **map_split)
{
	char	*temp;
	int		y;

	y = 0;
	while (map_split[y] && cub->map.index < 6)
	{
		temp = map_split[y];
		map_split[y] = ft_strtrim(temp, "\t");
		y++;
		free(temp);
	}
}

void	ft_trim_texture(t_cub *cub, char **map_split)
{
	char	*temp;
	int		y;

	y = 0;
	while (map_split[y] && cub->map.index < 6)
	{
		temp = map_split[y];
		map_split[y] = ft_strtrim(temp, "\t");
		if (y == 2)
			error_msg("Error\nInvalid texture : something after texture");
		y++;
		free(temp);
	}
}

void	ft_trim_colors(char **map_split)
{
	int		t;
	char	*temp;

	t = 2;
	while (map_split[t])
	{
		temp = map_split[1];
		map_split[1] = ft_strjoin_2(temp, map_split[t]);
		t++;
		free(temp);
	}
}
