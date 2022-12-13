/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:00 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 11:16:12 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	win_closed(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	printf("\033[0;32m" "Windows closed !\n" "\033[0m");
	exit(0);
}

int	key_mouse(int x, int y, t_cub *cub)
{
	(void)y;
	mlx_mouse_hide();
	if (x < SCREEN_W / 2)
		mouse_left(cub);
	if (x > SCREEN_W / 2)
		mouse_right(cub);
	mlx_mouse_move(cub->win, SCREEN_W / 2, SCREEN_H / 2);
	return (1);
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == W)
		move_forward(cub);
	if (keycode == S)
		move_backwards(cub);
	if (keycode == A)
		move_left(cub);
	if (keycode == D)
		move_right(cub);
	if (keycode == RIGHT)
		rotate_right(cub);
	if (keycode == LEFT)
		rotate_left(cub);
	if (keycode == ESC)
		win_closed(cub);
	return (0);
}

int	raycast_loop(t_cub *cub)
{
	ft_raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}

void	game_hook(t_cub *cub)
{	
	int	x;

	open_textures(cub);
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->img.addr = (int *) mlx_get_data_addr(cub->img.img,
			&cub->img.bits_per_pixel, &cub->img.line_length, &x);
	mlx_hook(cub->win, 2, 0, key_hook, cub);
	//mlx_hook(cub->win, 6, 0, key_mouse, cub);
	mlx_hook(cub->win, 17, 1L << 0, win_closed, cub);
	mlx_loop_hook(cub->mlx, raycast_loop, cub);
	mlx_loop(cub->mlx);
	free_tab(cub->map.str);
}
