# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 17:37:22 by zadriouc          #+#    #+#              #
#    Updated: 2024/05/11 14:30:26 by zadriouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_HEAD = ./libft/
MINI_TOOLS = ./minitalk_tools/
SRCS = ft_putnbr_base.c ft_putp.c ft_printf.c
LIBFT_SRC = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_atoi.c ft_atoi_c.c ft_itoa.c ft_strdup.c ft_strncmp.c
MINI_SRC = mini_banner.c show_zeros.c ft_allocate.c signal_error.c re_initialase.c build_character.c ft_increment.c bytes_nb.c ft_print_binary.c
LIBFT_SRCS = $(addprefix $(LIBFT_HEAD), $(LIBFT_SRC))
MINI_SRCS = $(addprefix $(MINI_TOOLS), $(MINI_SRC))
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIBFT_SRCS:.c=.o)
MINI_OBJS = $(MINI_SRCS:.c=.o)
NAME = libftprintf.a
AR = ar -crs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS) $(MINI_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(AR) $(NAME) $@
	
fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS) $(LIB_OBJS) $(MINI_OBJS)

re: fclean all

.PHONY: clean fclean all re
.SECONDARY: $(OBJS) $(LIB_OBJS) $(MINI_OBJS)
