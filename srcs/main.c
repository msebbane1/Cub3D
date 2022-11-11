/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:27 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	game_start(t_cub *cub)
{
	//int	keycode;

	//keycode = 0;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx,
			500, 500, "Cub3D");
	//open_images(*conf);
}

void	start_error(int ac, char **av)
{
	int		fd;
	int		fd2;
	char	c;

	if (ac > 2)
		error_msg("Error\nToo many arguments");
	else if (ac < 2)
		error_msg("Error\nMissing a file");
	else if (ft_strncmp(".cub", av[1] + ft_strlen(av[1]) - 4, 4))
		error_msg("Error\nMissing a file (.cub)");
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_DIRECTORY);
	if (fd < 0)
		error_msg("Error\nInvalid file :File doesn't exist");
	if (fd2 != -1)
		error_msg("Error\nFile invalid :Directory");
	if (read(fd, &c, 1) < 1)
		error_msg("Error\nInvalid file :Can't read file");
	close(fd);
	close(fd2);
}

void	game_hook(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length,
								&cub->img.endian);
	my_mlx_pixel_put(&cub->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	//mlx_hook(cub.win, 2, 1L << 0, key_hook, &cub);
	//mlx_hook(cub.win, 17, 1L << 0, win_closed, &cub);
	mlx_loop(cub->mlx);
}

void	init_parse(t_cub *cub)
{
	cub->map.index = 0;
	cub->map.index_spaces = 0;
	cub->player.nb_player = 0;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	init_parse(cub);
	start_error(argc, argv);
	malloc_map(argv, cub);
	read_map(argv, cub);
	check_valid_format(cub);
	check_valid_map(cub);
	// PARSING verfier si la map est valid check tout
	test_print(cub);
	//game_start(&cub);
	// afficher image check la taille des image que je vais recuperer
	// voir rayCasting
	//game_hook(&cub);
}
