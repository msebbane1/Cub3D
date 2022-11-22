# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 11:18:46 by msebbane          #+#    #+#              #
#    Updated: 2022/11/17 16:27:25 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

SRCS = GNL/get_next_line_utils.c GNL/get_next_line.c\
	   srcs/main.c libft/libft.c parsing/error_msg.c libft/ft_split.c parsing/check_valid_format.c\
	   parsing/read_map.c parsing/check_valid_map.c parsing/check_colors.c\
	   srcs/test_print.c libft/ft_strtrim.c srcs/open_img.c libft/ft_atoi.c\

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
		$(CC) $(OBJS) $(FLAGSMLX) $(CFLAGS) -o $(NAME)

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