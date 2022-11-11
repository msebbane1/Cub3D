# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 11:18:46 by msebbane          #+#    #+#              #
#    Updated: 2022/11/10 11:33:18 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

SRCS = GNL/get_next_line_utils.c GNL/get_next_line.c\
	   srcs/main.c srcs/libft.c srcs/error_msg.c srcs/ft_split.c srcs/check_valid_format.c\
	   srcs/malloc_map.c srcs/read_map.c srcs/check_valid_map.c\
	   srcs/test_print.c srcs/ft_strtrim.c srcs/open_img.c\

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