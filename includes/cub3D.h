/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:21:51 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 14:53:29y lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "key_hook.h"
# include "struct.h"
# include "../mlx/mlx.h"

int			main(int argc, char **argv);
//**********************************LIBFT********************************//
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char *s, char c);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *s);
int			ft_atoi(char *nptr);
//**********************************PARSING********************************//
void		read_map(char **av, t_cub *cub);
void		check_valid_map(t_cub *cub);
void		check_valid_format(t_cub *cub);
int			check_walls_first_line(t_cub *cub);
void		check_colors(t_cub *cub, char *str, char c);
void		check_texture_path(char	*path, int *error);
int			ft_char_texture(char *line);
int			create_trgb(int t, int r, int g, int b);
int			ft_check_letters(char *line);
void		remplace_map(t_cub *cub);
char		**split_map(t_cub *cub, int i, char **map_split);
//**********************************PARSING_UTILS****************************//
char		*ft_strjoin_2(char *s1, char *s2);
int			ft_skip_format(char *line);
int			check_char(char c);
int			check_new_index(t_cub *cub);
int			check_spaces(t_cub *cub, int l, int t);
int			check_virgule(char *str);
int			check_start_line(t_cub *cub);
void		ft_trim_format(t_cub *cub, char **map_split);
void		ft_trim_texture(t_cub *cub, char **map_split);
void		ft_trim_colors(char **map_split);
int         veref(t_cub *cub, int i);
void		free_tab(char **str);
char        *ft_strjoin_2(char *s1, char *s2);
//**********************************TEXTURES*****************************//
t_texture	init_img(void	*mlx, char *texture_path);
void		open_textures(t_cub *cub);
//**********************************GAME*****************************//
void		game_hook(t_cub *cub);
//**********************************PLAYER********************************//
void		position_player(t_cub *cub);
void		move_forward(t_cub *cub);
void		move_right(t_cub *cub);
void		mouse_right(t_cub *cub);
void		mouse_left(t_cub *cub);
void		move_left(t_cub *cub);
void		move_backwards(t_cub *cub);
void		rotate_right(t_cub *cub);
void		rotate_left(t_cub *cub);
//**********************************RAY_CASTING****************************//
void		draw_color_backgound(t_cub *cub);
void		ft_raycasting(t_cub *cub);
void		init_ray(t_cub *cub);
void		init_hit(t_cub *cub);
void		init_step(t_cub *cub);
void		init_ray_dist(t_cub *cub);
void		draw_walls(t_cub *cub, int start_draw, int end_draw);
//**********************************ERROR_MSG********************************//
char		error_msg(char *msg);

#endif