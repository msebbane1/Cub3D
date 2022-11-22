/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:13 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/15 16:21:23 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	copy_map(char **argv, t_cub *cub)
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
		//split_map = ft_split(line, ' ');
		cub->map.str[i++] = ft_strdup(line);
		free(line);
	}
	cub->map.str[i] = NULL;
	close(fd);
}

int	count_lines(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	return (i++);
}

void	read_map(char **av, t_cub *cub)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	cub->map.size.y = count_lines(fd);
	close(fd);
	cub->map.str = malloc(sizeof(char *) * (cub->map.size.y + 1));
	if (!cub->map.str)
		error_msg("Error\nWrong map");
	copy_map(av, cub);
}
