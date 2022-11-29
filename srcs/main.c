/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/29 12:16:11 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	game_start(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx,
			SCREEN_W, SCREEN_H, "Cub3D");
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

void	init_parse(t_cub *cub)
{
	cub->map.index = 0;
	cub->map.no = 0;
	cub->map.so = 0;
	cub->map.we = 0;
	cub->map.ea = 0;
	cub->map.c = 0;
	cub->map.f = 0;
	cub->map.index_spaces = 0;
	cub->player.nb_player = 0;
	cub->map.wall[0].img = NULL;
	cub->map.wall[1].img = NULL;
	cub->map.wall[2].img = NULL;
	cub->map.wall[3].img = NULL;
	cub->map.sky[0] = -1;
	cub->map.floor[0] = -1;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	init_parse(cub);
	start_error(argc, argv);
	read_map(argv, cub);
	check_valid_format(cub);
	check_valid_map(cub);
	remplace(cub);
	game_start(cub);
	game_hook(cub);
	//test_print(cub);
	// afficher image check la taille des image que je vais recuperer
	// voir rayCasting
}
