# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 18:39:31 by jvigny            #+#    #+#              #
#    Updated: 2023/02/08 17:28:31 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS =  -Wall -Werror -Wextra -g3
LFLAGS = -lmlx -lXext -lX11 -lm -L$(MINILIBX_DIR)
INCLUDES = -I$(MINILIBX_HEADERS) -I$(HEADERS_DIR)

MINILIBX_DIR = ./minilibx-linux/
MINILIBX_HEADERS = $(MINILIBX_DIR)
MINILIBX = $(MINILIBX_DIR)libmlx.a

HEADERS_LIST = fdf.h
HEADERS_DIR = ./Includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

GNL = get_next_line/
UTILS = utils/

SRC_LIST = fdf.c parsing.c rotation.c t_coordonnee_3d.c \
	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c \
	$(UTILS)ft_split.c $(UTILS)ft_atoi.c $(UTILS)ft_strlen.c draw_line.c \
	center_plan.c translation.c $(UTILS)utils.c init_game.c \
	link_point.c $(UTILS)free_split.c ft_move.c find_min_max.c key.c \
	fill_color.c color.c $(UTILS)ft_strdup.c projection.c error.c \
	put_pixel.c hook.c
SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

	
OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))


all:	$(NAME)

$(NAME):	$(MINILIBX) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LFLAGS) -o $(NAME)
	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(GNL)
	mkdir -p $(OBJ_DIR)$(UTILS)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(MINILIBX):
	make -C $(MINILIBX_DIR) all

clean:
	make -C $(MINILIBX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(MINILIBX)
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
