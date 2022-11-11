/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:13 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/10 10:21:11 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
int	count_lines_x(int fd)
{
	int		lines;
	int		ret;
	char	c;

	lines = 0;
	ret = 1;
	c = '\x00';
	while (ret == 1 && c != '\n')
	{
		ret = read(fd, &c, 1);
		lines++;
	}
	return (lines - 1);
}*/

/*int	count_lines(int fd)
{
	int		lines;
	int		ret;
	char	c;

	lines = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, &c, 1);
		if (c == '\n')
			lines++;
	}
	return (lines);
}*/


/*int	count_lines(int fd)
{
	int		lines;
	char	*r;

	lines = 0;
	r = 0;
	while (1)
	{
		r = get_next_line(fd);
		if (r == 0)
		{
			close(fd);
			break ;
		}
		free (r);
		lines++;
	}
	return (lines);
}*/
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

void	malloc_map(char **av, t_cub *cub)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	cub->map.size.y = count_lines(fd);
	close(fd);
	cub->map.str = malloc(sizeof(char *) * (cub->map.size.y + 1));
	if (!cub->map.str)
		error_msg("Error\nWrong map");
}
