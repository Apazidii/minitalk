NAME	= prog
FUNCS 	= test.c
FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -c
HDRS = head.h

all:		${NAME}

${NAME}:	${FUNCSO} ${HDRS}
			${GCC} ${FUNCSO} -o ${NAME}

.c.o:
			${GCC} ${CFLAGS} $< -o ${<:.c=.o}

clean:
		rm -f ${FUNCSO}

fclean:	clean
		rm -f ${NAME}

.PHONY:	all clean fclean
