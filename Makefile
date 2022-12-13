# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 11:18:46 by msebbane          #+#    #+#              #
#    Updated: 2022/12/13 13:11:47 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

CLINK= -framework OpenGL -framework AppKit

SRCS = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
	   get_next_line/gnl.c\
	   libft/libft.c libft/ft_split.c libft/ft_atoi.c libft/ft_strtrim.c\
	   parsing/error_msg.c parsing/parsing_utils2.c parsing/parsing_utils.c\
	   parsing/read_map.c parsing/check_valid_map.c parsing/check_colors.c\
	   parsing/remplace_map.c parsing/check_valid_format.c parsing/parsing_utils3.c\
	   parsing/split_map_format.c\
	   srcs/open_img.c srcs/main.c srcs/start_game.c\
	   srcs/draw_cub3d.c srcs/raycasting.c srcs/player.c\
	   srcs/init_raycasting.c srcs/movement.c srcs/rotation.c\

SRCS_BONUS = 

RM = rm -f

ifndef BONUS
SOURCES	= ./srcs
OBJS	= $(SRCS:.c=.o)
else
SOURCES	= ./srcs_bonus
OBJS	= $(SRCS_BONUS:.c=.o)
endif

all: ${NAME}

bonus:
	@echo "\033[1;32m""Compilation de ${NAME}..."
	@make BONUS=1 ${NAME}

${NAME}: ${OBJS}
		@echo "\033[1;36m""Compilation de ${NAME}..."
		$(CC) $(OBJS) $(CFLAGS) $(CLINK) libmlx.a -lncurses -o $(NAME)

${OBJECTS}/%.o: ${SOURCES}/%.c
	@echo "Compilation de ${notdir $<}."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@echo "\033[1;32m""Supression des fichiers binaires (.o)..."
		${RM} ${OBJS} $(SRCS_BONUS:.c=.o)

fclean: clean
		@echo "\033[1;32m""Supression des executables et librairies..."
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all

.PHONY: all bonus clean fclean re