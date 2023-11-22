# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 03:18:07 by acanelas          #+#    #+#              #
#    Updated: 2023/11/15 23:02:39 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/check_input.c \
		srcs/check_n_get_map.c \
		srcs/inicialize.c \
		srcs/rgb_n_textures.c \
		srcs/rgb_n_textures2.c \
		srcs/str_util.c \
		srcs/get_map_utils.c \
		srcs/init_graphics.c \
		srcs/render_map.c \
		srcs/ray_casting.c \
		srcs/ray_utils.c \
		srcs/move_player.c \
		srcs/rotate_player.c \
		srcs/free_destroy.c \
		srcs/get_tex.c \
		srcs/main.c \

NAME = cub3d
RM = rm -rf
LIBFT = ./libft/libft.a
CC = cc
MATH = -lm
CFLAGS = -Wall -Wextra -Werror
CCMLX = -L ./minilibx -lmlx -Ilmlx -lXext -lX11 -lbsd

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CCMLX) $(MATH) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re