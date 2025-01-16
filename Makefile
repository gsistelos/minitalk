CLIENT = client
SERVER = server

SRC_CLIENT = client.c validate_args.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f


.PHONY: all
all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) -o $(CLIENT) $(OBJ_CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) -o $(SERVER) $(OBJ_SERVER)

.PHONY: clean
clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

.PHONY: fclean
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

.PHONY: re
re: fclean all
