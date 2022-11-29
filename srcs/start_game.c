/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:00 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/29 14:39:28 by lbally           ###   ########.fr       */
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

void	init_rayon(t_ray *ray)
{
	ray->x = 0;
	ray->y = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->dist = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->wallx = 0;
	ray->nb = 0;
	ray->h = 0;
}

int	loop(t_cub	*cub)
{
	t_ray	*ray;
	//ft_key(cub); // mouvement
	ray = malloc(sizeof(t_ray));
	//init_rayon(ray);
	draw_color_backgound(cub);
	raycasting(ray, cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}

void	game_hook(t_cub *cub)
{	
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->img.addr = (int *) mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	//Init player faire mouvement + position
	player(cub);
	mlx_hook(cub->win, 2, 1L << 0, key_hook, cub);
	//mlx_hook(cub->win, 2, 0, ft_key_press, cub); // key avec move 
	//mlx_hook(cub->win, 3, 0, ft_key_release, cub);
	mlx_hook(cub->win, 17, 1L << 0, win_closed, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	mlx_loop(cub->mlx);
}
