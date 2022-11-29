/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:42:06 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/28 15:11:54 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_player_walls(t_cub *cub, int l, int c)
{
	int	size_l2;

	size_l2 = ft_strlen(cub->map.str[l - 1]);
	if (cub->map.str[l][c] == 'N' || cub->map.str[l][c] == 'S' ||
		cub->map.str[l][c] == 'W' || cub->map.str[l][c] == 'E')
	{
		if (l + 1 == cub->map.size.y)
			return (1);
		if (size_l2 < c || cub->map.str[l - 1][c] == ' '
			|| cub->map.str[l - 1][c] == '\0')
			return (1);
		if (cub->map.str[l + 1] != NULL)
		{
			if (ft_strlen(cub->map.str[l + 1]) < c
				|| cub->map.str[l + 1][c] == ' '
					|| cub->map.str[l + 1][c] == '\0')
				return (1);
		}
		if (cub->map.str[l][c + 1] == ' ' || cub->map.str[l][c + 1] == '\0')
			return (1);
		if (cub->map.str[l][c - 1] == ' ' || cub->map.str[l][c - 1] == '\0')
			return (1);
	}
	return (0);
}

int	check_walls_zero(t_cub *cub, int l, int c)
{
	int	size_l2;

	size_l2 = ft_strlen(cub->map.str[l - 1]);
	if (cub->map.str[l][c] == '0')
	{
/*		if (l + 1 == cub->map.size.y)
		{
			printf("LALA1\n");
			return (1);
		}*/
		if (size_l2 < c || cub->map.str[l - 1][c] == ' '
			|| cub->map.str[l - 1][c] == '\0')
			return (1);
		if (cub->map.str[l + 1] != NULL)
		{
			if (ft_strlen(cub->map.str[l + 1]) < c
				|| cub->map.str[l + 1][c] == ' '
					|| cub->map.str[l + 1][c] == '\0')
				return (1);
		}
		if (cub->map.str[l][c + 1] == ' ' || cub->map.str[l][c + 1] == '\0')
			return (1);
		if (cub->map.str[l][c - 1] == ' ' || cub->map.str[l][c - 1] == '\0')
			return (1);
	}
	return (0);
}

int	check_walls_first_line_char(t_cub *cub)
{
	int		c;
	int		l;

	l = cub->map.index_spaces;
	c = 0;
	while (cub->map.str[l] != NULL)
	{
		if (cub->map.str[l][0] == '0' || cub->map.str[l][0] == 'N'
			|| cub->map.str[l][0] == 'W' || cub->map.str[l][0] == 'E'
			|| cub->map.str[l][0] == 'S')
			return (1);
		l++;
	}
	return (0);
}

int	check_walls_first_line(t_cub *cub)
{
	int		c;
	int		l;

	l = cub->map.index_spaces;
	c = 0;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			while (cub->map.str[l][c] == ' ')
				c++;
			if (cub->map.str[cub->map.index_spaces][c] != '1')
			{
				if (cub->map.index_spaces != l)
					break ;
				return (1);
			}
			c++;
		}
		l++;
	}
	return (0);
}

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E'
		&& c != ' ' && c != '\t'
		&& c != '\r' && c != '\f'
		&& c != '\v')
		return (1);
	return (0);
}

int	check_player_pos(t_cub *cub, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (cub->player.nb_player == 1)
			return (1);
		cub->player.nb_player = 1;
		return (0);
	}
	return (0);
}

int	check_spaces(t_cub *cub)
{
	int		l;
	int		t;

	l = cub->map.index_spaces;
	t = 0;
	printf("index_spaces = %d\n", l);
	while (cub->map.str[l] != NULL)
	{
		while (cub->map.str[l][0] != '\n' && cub->map.str[l][0] != '\0')
		{
			if (cub->map.str[l] != NULL)
				break ;
			if (t != 0)
				return (1);
			l++;
		}
		t++;
		l++;
	}
	return (0);
}

void	check_valid_map(t_cub *cub)
{
	int		l;
	int		c;
	int		y;

	l = cub->map.index_spaces;
	c = 0;
	y = cub->map.index_spaces;
	printf("index_spaces = %d\n", l);
	if (check_spaces(cub))
		error_msg("Error\nInvalid map something is empty");
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			if (check_char(cub->map.str[l][c]))
				error_msg("Error\nInvalid characters in your map");
			if (check_player_pos(cub, cub->map.str[l][c]))
				error_msg("Error\nToo much players");
			if (check_walls_zero(cub, l, c))
				error_msg("Error\nInvalid map not closed[zero]");
			if (check_player_walls(cub, l, c))
				error_msg("Error\nPlayer outside the map[not closed]");
			c++;
		}
		l++;
	}
	if (check_walls_first_line_char(cub))
		error_msg("Error\nInvalid map not closed[firstchar]");
	if (cub->player.nb_player != 1)
		error_msg("Error\nNeed one player");
	cub->map.size.x = c;
}
