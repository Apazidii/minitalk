NAME	= prog
FUNCS 	=		\
				ft_utils.c s1.c
FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c
HDRS = minitalk.h

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
