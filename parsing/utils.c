/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:51:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:37 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
