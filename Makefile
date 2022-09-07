NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread -g

SRC     =       main.c          \
				utils.c			\
				init.c			\
				parsing.c		\
				print.c			\
				routine.c		\
				live.c			\

OBJS = ${SRC:.c=.o}

all:    ${NAME}

${NAME}:${OBJS}
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o:    %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re
