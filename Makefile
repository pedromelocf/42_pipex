#LIBFT
LIBFT_DIR = ./lib
LIBFT_PATH = ./lib/libft/*.o ./lib/libft/*.a
LIB_PATH = ./lib/*.a
GNL_OBJ = ./lib/gnl/*.o
PRINTF_OBJ = ./lib/printf/*.o

#PIPEX
NAME = pipex
PIPEX_SRC_PATH = ./pipex_utils/
PIPEX_INCLUDES = ./includes/pipex.h
PIPEX_OBJ = $(addprefix $(PIPEX_SRC_PATH), $(PIPEX_SRCS:.c=.o))

PIPEX_SRCS = main.c \
	utils.c

#FLAGS
FLAGS = -Wall -Werror -Wextra
CC = cc
MAKEFLAG += make --no-print-directory

all: libft $(NAME)

$(NAME): $(PIPEX_OBJ)
	$(CC) $(FLAGS) $(PIPEX_OBJ) $(LIB_PATH) -o $(NAME)

$(PIPEX_SRC_PATH)%.o: $(PIPEX_SRC_PATH)%.c $(PIPEX_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(PIPEX_OBJ) $(LIBFT_PATH) $(LIB_PATH) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re pipex
