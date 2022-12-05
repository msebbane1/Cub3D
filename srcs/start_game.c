/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:00 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/05 18:15:51 by msebbane         ###   ########.fr       */
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
	if (keycode == W)
	{
		printf("w\n");
		//move_up(cub);
	}
	if (keycode == ESC)
		win_closed(cub);
	return (0);
}

void	game_hook(t_cub *cub)
{	
	int	x;

	cub->img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->img.addr = (int *) mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &x);
	draw_color_backgound(cub);
	ft_raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_hook(cub->win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->win, 17, 1L << 0, win_closed, cub);
	mlx_loop(cub->mlx);
}
