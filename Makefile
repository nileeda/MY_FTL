CC	=	gcc
NAME	=	my_ftl
SRC	=	main.c \
		air_shed.c \
		my_strcpy.c \
		my_put_nbr.c \
		container.c \
		my_string.c \
		system_control.c \
		system_repair.c \
		readline.c \
		game_functions.c \
		gameloop.c \
		ennemy.c \
		player.c
OBJS	=	$(SRC:%.c=%.o)
RM	=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
.PHONY	:	clean re all fclean
