# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 20:40:02 by tsirirak          #+#    #+#              #
#    Updated: 2022/12/19 19:47:49 by tsirirak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= check_file.c \
					check_map.c \
					so_long.c \
					render.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
HEAD 			= -Imlx -I/libft
LIB				= libft/libft.a mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME			= so_long
LIBDIR			= ./libft
MLXDIR			= ./mlx
LIBFT           = ./libft


%.o: %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBDIR) 
	make -C $(MLXDIR)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

all:			$(NAME)

clean:
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean:			clean
	make -C $(LIBDIR) fclean
	$(RM) $(NAME)

re:				fclean $(NAME)
	make -C $(LIBDIR) re

.PHONY:			all clean fclean re bonus
