NAME = libftprintf.a

LIBFT_DIR = libft
LIB_PATH = ./libft/*.o ./libft/*.a

#GNL
GNL_SRC_PATH = ./gnl/
GNL_INCLUDES = ./gnl/get_next_line.h
GNL_OBJ = $(addprefix $(GNL_SRC_PATH), $(GNL_SRCS:.c=.o))

GNL_SRCS = get_next_line_utils.c \
	get_next_line.c

#PRINTF
PRINTF_SRC_PATH = ./printf/
PRINTF_INCLUDES = ./printf/ft_printf.h
PRINTF_OBJ = $(addprefix $(PRINTF_SRC_PATH), $(PRINTF_SRCS:.c=.o))

PRINTF_SRCS = ft_check_conversion.c \
	ft_check_conversion_fd.c \
	ft_dprintf.c \
	ft_printf.c \
	ft_putchar.c \
	ft_put_hex.c \
	ft_putnbr_base.c \
	ft_putnbr.c \
	ft_putnbr_hex.c \
	ft_putstr.c \
	ft_put_unsigned.c \
	ft_put_void_pointer.c

FLAGS = -Wall -Werror -Wextra
CC = cc
MAKEFLAG += make --no-print-directory

#MESSAGES
MESSAGE1 = "--------------Compiling Get Next Line Objects!---------------"
MESSAGE2 = "-------------GNL Objects Compiled Successfully!--------------"
MESSAGE3 = "----------Printf Objects Compiled Successfully!--------------"
MESSAGE4 = "-------------------- All Objects cleaned!--------------------"
MESSAGE5 = "-------------------- All Binaries cleaned!-------------------"
MESSAGE6 = "-------------------- Copying Libft Binarie-------------------"
MESSAGE7 = "-------------libftprintf.a Compiled Successfully-------------"
MESSAGE8 = "-----------------Compiling Printf Objects!-------------------"

all: libft $(NAME)

$(NAME): $(GNL_OBJ) $(PRINTF_OBJ)
	@ echo $(MESSAGE6)
	@ echo ' '
	@ cp $(LIBFT_DIR)/libft.a $(NAME)
	@ echo $(MESSAGE1)
	@ echo ' '
	@ echo $(MESSAGE2)
	@ echo ' '
	@ echo $(MESSAGE8)
	@ echo ' '
	@ echo $(MESSAGE3)
	@ ar rcs $(NAME) $(GNL_OBJ) $(PRINTF_OBJ)
	@ echo ' '
	@ echo $(MESSAGE7)
	@ echo ' '

$(GNL_SRC_PATH)%.o: $(GNL_SRC_PATH)%.c $(GNL_INCLUDES)
	@ $(CC) $(FLAGS) -c $< -o $@

$(PRINTF_SRC_PATH)%.o: $(PRINTF_SRC_PATH)%.c $(PRINTF_INCLUDES)
	@ $(CC) $(FLAGS) -c $< -o $@

clean :
	@ rm -f $(LIB_PATH) $(GNL_OBJ) $(PRINTF_OBJ)
	@ echo $(MESSAGE4)
	@ echo ' '

fclean : clean
	@ rm -f $(NAME)
	@ echo $(MESSAGE5)
	@ echo ' '

re : fclean all

libft :
	@ $(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft
