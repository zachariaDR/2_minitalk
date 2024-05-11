
# Binary Name:
NAME	=	
CLIENT	=	client
SERVER	=	server

#ft_printf Variables:
LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

#minitalk variables
SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
OBJ_S	=	ft_server.o
OBJ_C	=	ft_client.o
INC		=	ft_minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf


all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS)  $(OBJ_S) $(LIBFTPRINTF) -o $@ 
	@printf "server ready.\n"

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS)  $(OBJ_C) $(LIBFTPRINTF) -o $@ 
	@printf "client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF): $(LIBFTPRINTF_DIR)
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "client removed.\n"
	@printf "server removed.\n"

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: ft_server.o ft_client.o
