# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 20:40:02 by tsirirak          #+#    #+#              #
#    Updated: 2022/12/18 21:02:20 by tsirirak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= check_file.c \
check_map.c \
mlx.c \
so_long.c \
					

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.



NAME			= so_long
LIBDIR			= ./libft
MLXDIR			= ./mlx

all:			$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBDIR) 
	make -C $(MLXDIR)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS)

fclean:			clean
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) fclean
	$(RM) $(NAME)

re:				fclean $(NAME)
	make -C $(LIBDIR) re
	make -C $(MLXDIR) re

.PHONY:			all clean fclean re bonus
