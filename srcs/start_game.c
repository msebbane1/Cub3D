/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:00 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 08:42:47 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	win_closed(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	printf("\033[0;32m" "Windows closed !\n" "\033[0m");
	exit (0);
}

int	key_hook(int keycode, t_cub *cub)
{
	//if (keycode == D || keycode == S || keycode == A || keycode == W
		//|| keycode == ESC)
		//faire mouvement;
	if (keycode == ESC)
		win_closed(cub);
	return (0);
}

int	loop(t_cub	*cub)
{
	//ft_key(cub); // mouvement
	draw_color_backgound(cub);
	//raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}

void	game_hook(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	//Init player faire mouvement + position
	mlx_hook(cub->win, 2, 1L << 0, key_hook, cub);
	//mlx_hook(cub->win, 2, 0, ft_key_press, cub); // key avec move 
	//mlx_hook(cub->win, 3, 0, ft_key_release, cub);
	mlx_hook(cub->win, 17, 1L << 0, win_closed, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	mlx_loop(cub->mlx);
}
