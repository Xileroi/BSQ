NAME	=	bsq

SRCS	=	main.c	\
				init_map.c	\
				useful_function.c	\
				check_map.c	\
				print_map.c \
				algo.c	\
				verif.c	\
				verif_file.c \
		

OBJ =	${SRCS:.c=.o}

CC =	cc -g3

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		$(CC) $(CFLAGS) -o $(NAME) ${OBJ}

all:	${NAME}

clean:
		rm -f ${OBJ}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
