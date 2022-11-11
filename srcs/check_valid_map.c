/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:42:06 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/11 12:44:22 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*int	check_walls(t_cub *cub)
{
	int	l;
	int	c;
	int	index_1;
	int	index_spaces;

	l = cub->map.index_spaces;
	index_1 = 0;
	index_spaces = 0;
	while (cub->map.str[l])
	{
		c = 0;
		index_1 = 0;
		while (cub->map.str[l][c])
		{
			if (cub->map.str[l][c] == '1' || cub->map.str[l][c] == '0')
				index_1++;
			while (cub->map.str[l][c] == ' ')
			{
				index_spaces++;
				c++;
			}
			if (index_spaces != 0)
			{
				if (index_1 != 0)
			}
		}
		l++;
	}
}*/

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
		&& c != 'E' && c != 'W' && c != ' ')
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

void	check_valid_map(t_cub *cub)
{
	int		l;
	int		c;
	int		y;

	l = cub->map.index_spaces;
	y = 0;
	c = 0;
	printf("l = %d\n", l);
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			if (check_char(cub->map.str[l][c]))
				error_msg("Error\nInvalid characters in your map");
			if (check_player_pos(cub, cub->map.str[l][c]))
				error_msg("Error\nToo much players");
			c++;
		}
		l++;
	}
	cub->map.size.x = c;
	if (check_walls_first_line(cub))
		error_msg("Error\nInvalid map not closed");
	/*if (check_walls_zero(cub))
		error_msg("Error\nInvalid map not closed");*/
	if (cub->player.nb_player != 1)
		error_msg("Error\n Need one player");
	/*if(l < 7 && check_valid_map)
		error_msg("Error\nMissing map");*/
	//if (check_walls(cub))
		//error_msg("Error\nInvalid walls");
	//else if (check_double(cub))
		//error_msg("Error\nToo much player or wrong position");
}