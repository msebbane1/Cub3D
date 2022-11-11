/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:51:48 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/10 14:01:19 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*int	checkparam(char **str)
{
	int	i;

	i = 0;
	if (str[i])
		i++;
	if (i > 2)
		return (1);
	return (1);
}*/

void	read_map(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;
	int		i;
	char	**split_map;

	line = NULL;
	i = 0;
	split_map = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		//if (ft_strcmp(*split_map, "\n"))
		//split_map = ft_split(line, '\n');
		cub->map.str[i++] = ft_strdup(line);
		free(line);
		//split_map = ft_strtrim(line, " ");
	}
	cub->map.str[i] = NULL;
	close(fd);
}
