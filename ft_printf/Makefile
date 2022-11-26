SRCS			= ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_16.c ft_putnbr_16mini.c ft_putnbr_p.c ft_putnbr_un.c ft_putstr.c ft_strlen.c


OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
