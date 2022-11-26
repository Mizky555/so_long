# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 20:55:34 by tsirirak          #+#    #+#              #
#    Updated: 2022/11/26 21:03:10 by tsirirak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= so_long.C

LIBDIR			= ./libft
LIBPF			= ./ft_printf

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long

all:			$(NAME)

$(NAME):		$(OBJS)
					$(CC) (CFLAGS) $(NAME) $(OBJS)
					make -C $()
clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
