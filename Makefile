PATH_SRC = ./src/
CLIENT = client
SERVER = server

UTILS = ./ft_utils1.c ./ft_utils2.c
FILES_S = ./server.c
FILES_C = ./client.c

OBJ_UTILS = $(UTILS:.c=.o)
OBJ_SERVER = $(FILES_S:.c=.o)
OBJ_CLIENT = $(FILES_C:.c=.o)

HDR = minitalk.h
MAKE = Makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)


$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS) $(HDR) $(MAKE)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS) $(HDR) $(MAKE)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

bonus: all

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)

fclean:	clean
	$(RM) server client

re: fclean all

.PHONY: all bonus re clean fclean