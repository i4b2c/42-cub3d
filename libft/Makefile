NAME = libft.a
SRC = src/ft_isalpha.c \
      src/ft_isdigit.c \
      src/ft_isalnum.c \
      src/ft_isascii.c \
      src/ft_isprint.c\
      src/ft_strlen.c \
      src/ft_memset.c \
      src/ft_bzero.c \
      src/ft_memcpy.c \
      src/ft_memmove.c \
      src/ft_strlcpy.c\
      src/ft_strcpy.c\
      src/ft_strlcat.c \
      src/ft_toupper.c \
      src/ft_tolower.c \
      src/ft_strchr.c \
      src/ft_strrchr.c \
      src/ft_strncmp.c\
      src/ft_memchr.c \
      src/ft_memcmp.c \
      src/ft_strnstr.c \
      src/ft_atoi.c \
      src/ft_calloc.c \
      src/ft_strdup.c\
      src/ft_substr.c \
      src/ft_strjoin.c \
      src/ft_strtrim.c \
      src/ft_split.c \
      src/ft_itoa.c \
      src/ft_strmapi.c\
      src/ft_striteri.c \
      src/ft_putchar_fd.c \
      src/ft_putstr_fd.c \
      src/ft_putendl_fd.c \
      src/ft_putnbr_fd.c\
      src/ft_lstnew.c \
      src/ft_lstadd_front.c \
      src/ft_lstsize.c \
      src/ft_lstlast.c \
      src/ft_lstadd_back.c\
      src/ft_lstdelone.c \
      src/ft_lstclear.c \
      src/ft_lstiter.c \
      src/ft_lstmap.c \
      src/ft_printf_utils1.c \
      src/ft_printf_utils2.c \
      src/len.c \
      src/ft_printf.c \
      src/ft_strlen.c \
      src/get_next_line.c \
      src/get_next_line_utils.c \

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXTRA = libft.so a.out

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
		@$(AR) $(NAME) $(BONUS_OBJ) $(OBJ)

clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
		@$(RM) $(NAME)
so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS_SRC)
	@gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)
extra:
	@$(RM) $(EXTRA)
re: fclean all

.SILENT: all fclean clean bonus
