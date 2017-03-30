CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_memalloc.c ft_memccpy.c \
	ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memdel.c \
	ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
	ft_strncpy.c ft_strnew.c ft_strstr.c ft_strnstr.c \
	ft_strdup.c ft_strequ.c ft_strnequ.c ft_strmap.c \
	ft_strmapi.c ft_strncmp.c ft_strlen.c ft_strclr.c \
	ft_strrchr.c ft_strsplit.c ft_strsub.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strdel.c \
	ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strtrim.c ft_itoa.c ft_strrev.c ft_min.c \
	get_next_line.c

OBJ = $(SRCS:.c=.o)

.PHONY: all comp clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
