/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:46:29 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/09 09:59:46 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


/*fonction qui check les 0 autour pas de vide*/

int	check_walls(t_cub *cub)
{
	int		l;
	int		c;
	int		y;
	int		r;
	int		w;
	int		t;

	l = 0;
	y = 0;
	c = 0;
	r = 0;
	w = 0;
	t = 0;
	while (cub->map.str[l] != NULL)
	{
		if (cub->map.str[l] == '\0')
			return (1);
		while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			if (cub->map.str[l][c] == '1' || cub->map.str[l][c - t] == '0')
				w++;
			while (cub->map.str[l][c] == ' ')
			{
				t++;
				c++;
			}
			if (t != 0)
			{
				if (w != 0)
				{
					if (cub->map.str[l][c - (t + 1)] != '1')
						return (1);
				}
				if (cub->map.str[l][c] != '1')
					return (1);
			}
			if (t == 0 && c == 0)
			{
				if (cub->map.str[l][0] != '1')
					return (1);
			}
			if (cub->map.str[l][c] == '0') //&& l != d->start)
			{
				while (cub->map.str[l - 1][r])
					r++;
				if (r - 1 < c)
					return (1);
				r = 0;
				while (cub->map.str[l + 1][r])
					r++;
				if (r - 1 < c)
					return (1);
				r = 0;
				if (cub->map.str[l - 1][c] == ' ' || cub->map.str[l + 1][c] == ' ')
					return (1);
			}
			c++;
			t = 0;
		}
		c = 0;
		w = 0;
		l++;
		/*while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			c++;
		}*/
	}
	return (0);
}
/*
int	check_walls(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((cub->map.str[y][x]) != '\0' && (cub->map.str[y][x]) != '\n')
	{
		while (cub->map.str[y][x] == ' ')
				x++;
		if (cub->map.str[y][x] != '1' && cub->map.str[y][x] != ' ')
			return (1);
		if (cub->map.str[cub->map.size.y - 1][x] != '1'
			&& cub->map.str[cub->map.size.y - 1][x] != ' ')
			return (1);
		x++;
	}
	x = 0;
	while (y < cub->map.size.y)
	{
		while (cub->map.str[y][x] == ' ')
				x++;
		if (cub->map.str[y][0] != '1' && cub->map.str[y][0] != ' ')
			return (1);
		else if (cub->map.str[y][cub->map.size.x - 1] != '1'
			&& cub->map.str[y][cub->map.size.x - 1] != ' ')
			return (1);
		y++;
	}
	return (0);
}*/

int	check_char(char c)
{
	if (c != '0' && c != '1')
	{
		if (c != 'N' && c != 'S'
			&& c != 'E' && c != 'W' && c != ' ')
			return (1);
	}
	return (0);
}

int	check_zero(t_cub *cub, int i, int j)
{
	int	c;
	int l;

	l = 0;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			if (i == 0 && cub->map.str[l][c] == '0')
				return (1);
			if (cub->map.str[l - 1][c] == ' ' || i == 0 ||
				cub->map.str[l - 1][c] == '\0' || (int)ft_strlen(cub->map.str[l - 1]) < j)
				return (1);
			if (cub->map.str[l - 1][c + 1] == ' ' || cub->map.str[l - 1][c + 1] == '\0')
				return (1);
			if (cub->map.str[l - 1][c - 1] == ' ' || j == 0)
				return (1);
			if (cub->map.str[l + 1] != NULL)
			{
				if (cub->map.str[l + 1][c] == ' ' || cub->map.str[l + 1][c] == '\0'
					|| (int)ft_strlen(cub->map.str[l + 1]) < j)
					return (1);
			}
			else
				return (1);
			c++;
		}
		l++;
	}
	return(0);
}


/*Parcours ma map puis verifie dans chaque ligne les caracteres autorisee*/
void	check_valid_map(t_cub *cub)
{
	int		l;
	int		c;
	int		y;

	l = 0;
	y = 0;
	c = 0;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
		{
			while (cub->map.str[l][c] == ' ')
				c++;
			if (check_char(cub->map.str[l][c]))
				error_msg("Error\nInvalid characters in your map");
			c++;
		}
		l++;
	}
	if (check_walls(cub))
		error_msg("Error\nInvalid walls");
	/*else if (check_double(cub))
		error_msg("Error\nToo much player or wrong position");*/
}


/**
 * un paramètre (texture/couleur) est défini 2 fois
 * un paramètre n'a pas été décrit ou est décrit après la map
 * fichier de texture existe pas
 * fichier de texture qui est un dossier
 * fichier de texture qui finit pas par .xpm
 * couleur contient pas 3 nombres
 * que des nombres pour les couleurs (is digit)
 * un nombre est plus petit que 0 ou plus grand que 255
 * un paramètre est mal décrit (exemple: la ligne du nord commence par NOO et pas NO)
 * mauvais caractère dans la map
 * espace pas entouré par des murs ou par un autre espace
 * trop de positions de départ
 * aucune position de départ
 * map pas entouré de mur
 * Taille de l'ecran
 * Textures mur face = NO = nord SO = sud EA = est WE = ouest
 * F = couleur du sol
 **/
