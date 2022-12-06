/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:21:51 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:46 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../g/get_next_line.h"
# include "key_hook.h"
# include "struct.h"

int		main(int argc, char **argv);

//**********************************LIBFT********************************//
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *s, char c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *s);
char	**ft_split2(char *str, char c);
//**********************************PARSING********************************//
void	read_map(char **av, t_cub *cub);
void	check_valid_map(t_cub *cub);
void	check_valid_format(t_cub *cub);
int		check_char(char c);
int		check_walls_first_line_char(t_cub *cub);
void	check_colors(t_cub *cub, char *str, char c);
int		ft_atoi(char *nptr);
int		check_params(char **str);
void	check_texture_path(char	*path);
int		ft_skip_format(char *line);
int		ft_char_texture(char *line);
int		create_trgb(int t, int r, int g, int b);
//**********************************REMPLACE******************************//
void	remplace(t_cub *cub);
//**********************************TEXTURES*****************************//
t_img	init_img(void	*mlx, char *path);
//***********************************DRAW***************************//
void	draw_color_backgound(t_cub *cub);
//**********************************GAME*****************************//
void	game_hook(t_cub *cub);
//**********************************PLAYER********************************//
void	position_player(t_cub *cub);
void	move_forward(t_cub *cub);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);
void	move_backwards(t_cub *cub);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);
//**********************************RAY_CASTING****************************//
void	ft_raycasting(t_cub *cub);
void	init_ray(t_cub *cub);
void	init_hit(t_cub *cub);
void	init_step(t_cub *cub);
void	init_ray_dist(t_cub *cub);
//**********************************ERROR_MSG********************************//
char	error_msg(char *msg);
//**********************************TEST PRINT********************************//
void	test_print(t_cub *cub);

#endif