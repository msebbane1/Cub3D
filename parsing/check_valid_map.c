/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:42:06 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 13:46:08 by msebbane         ###   ########.fr       */
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
		if (l == cub->map.size.y)
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
		if (l == cub->map.size.y)
			return (1);
		if (size_l2 < c || cub->map.str[l - 1][c] == ' '
			|| cub->map.str[l - 1][c] == '\0')
		{
			return (1);
		}
		if (cub->map.str[l + 1] != NULL)
		{
			if (ft_strlen(cub->map.str[l + 1]) < c
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

void	parse_map(t_cub *cub, int l, int c)
{
	if (check_char(cub->map.str[l][c]))
		error_msg("Error\nInvalid characters");
	if (check_player_pos(cub, cub->map.str[l][c]))
		error_msg("Error\nInvalid player :Too much players");
	if (check_walls_zero(cub, l, c))
		error_msg("Error\nInvalid map :map not closed[zero]");
	if (check_player_walls(cub, l, c))
		error_msg("Error\nInvalid player: player outside the map[not closed]");
}

void	check_valid_map(t_cub *cub)
{
	int		l;
	int		c;
	int		t;

	l = cub->map.index_map;
	t = 0;
	if (check_start_line(cub))
		error_msg("Error\nInvalid map");
	if (check_spaces(cub, l, t))
		error_msg("Error\nInvalid map something is empty");
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			parse_map(cub, l, c);
			c++;
		}
		l++;
	}
	if (cub->player.nb_player != 1)
		error_msg("Error\nInvalid map : need one player");
	if (check_walls_first_line(cub))
		error_msg("Error\nInvalid map :map not closed[firstchar]");
}
