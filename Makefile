INC= Includes/
SRC_DIR = src/
OBJ_DIR = obj/
GNL = get_next_line/

SRC = $(addprefix $(SRC_DIR),\
	fdf.c parsing.c rotation.c t_coordonnee_3d.c \
	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c \
	ft_split.c ft_atoi.c ft_strlen.c draw_line.c \
	affichage.c add_z.c center_plan.c translation.c \
	link_point.c free_split.c ft_move.c)
	
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

NAME= fdf
HEADER= ${INC}/fdf.h ${INC}/mlx.h 
CC= cc
CFLAGS=  -Wall -Werror -Wextra -g3 -I$(INC) 
LFLAGS = -L$(INC) -lmlx -lXext -lX11 -lm

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(GNL)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: clean all

.PHONY : all clean fclean re bonus
