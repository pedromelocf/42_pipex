NAME = libft.a

SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJ = $(SRCS:.c=.o)
INCLUDES = ../libft.h
FLAGS = -Wall -Werror -Wextra

#MESSAGES
MESSAGE1 = "------------------Compiling Libft Objects!------------------"
MESSAGE2 = "---------------Objects Compiled Successfully!----------------"
MESSAGE3 = "----------------libft.a Compiled Successfully!---------------"
MESSAGE4 = "-------------------- Libft Objects cleaned!------------------"
MESSAGE5 = "-------------------- Libft Binarie cleaned!------------------"

all: $(NAME)

$(NAME): $(OBJ)
	@ echo $(MESSAGE1)
	@ ar rcs $(NAME) $(OBJ)
	@ echo ' '
	@ echo $(MESSAGE2)
	@ echo ' '
	@ echo $(MESSAGE3)
	@ echo ' '
	@ echo ' '

%.o: %.c $(INCLUDES)
	@ $(CC) $(FLAGS) -c $< -o $@

clean :
	@ rm -f $(OBJ)
	@ echo $(MESSAGE4)
	@ echo ' '

fclean : clean
	@ rm -f $(NAME)
	@ echo $(MESSAGE5)
	@ echo ' '

re : fclean all

.PHONY: all clean fclean re
