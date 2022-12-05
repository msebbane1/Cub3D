/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 07:01:02 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/05 13:57:18 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
// génère des textures
   pour (int x = 0; x < texWidth; x++)
  for(int y = 0; y < texHeight; y++)
  {
    int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    //int xcolor = x * 256 / texWidth ;
    int ycolor = y * 256 / texHeight;
    int xycolor = y * 128 / texHeight + x * 128 / texWidth ;
    texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //texture plate rouge avec texture croix noire
     [1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //
     texture inclinée en niveaux de gris[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //
     texture dégradé jaune incliné[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor
     texture en niveaux de gris[4][texWidth * y + x] = 256 * xorcolor; //
     texture verte xor[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //
     texture de briques rouges[6][texWidth * y + x] = 65536 * ycolor; //dégradé rouge
    texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128 ; //texture grise plate
   }
*/
/*
RATIO : -1 = gauche de l'ecran 0 = centre 1 = droite
*/
/*void	draw_walls(t_cub *cub)
{
	double	ratio;

	ratio = ((double) SCREEN_W / (double) SCREEN_H);
}*/
void	draw_color_backgound(t_cub *cub)
{
	int	middle_screen;
	int	x;

	middle_screen = SCREEN_W * SCREEN_H / 2 - 1;
	x = SCREEN_W * SCREEN_H - 1;
	while (x >= middle_screen)
	{
		cub->img.addr[x] = cub->map.color_floor;
		x--;
	}
	while (x >= 0)
	{
		cub->img.addr[x] = cub->map.color_sky;
		x--;
	}
}
