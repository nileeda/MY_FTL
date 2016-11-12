##
## Makefile for  in /home/nileeda/Documents/C/My_FTL/patin_a
## 
## Made by PATIN Adeline
## Login   <patin_a@etna-alternance.net>
## 
## Started on  Sat Nov 12 12:01:33 2016 PATIN Adeline
## Last update Sat Nov 12 12:01:36 2016 PATIN Adeline
##

CC	=	gcc
NAME	=	my_ftl
SRC	=	main.c \
		air_shed.c \
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
