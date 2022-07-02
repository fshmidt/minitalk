# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 00:51:43 by mbesan            #+#    #+#              #
#    Updated: 2021/11/09 17:50:24 by mbesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc

CFLAGS		=	-Wall -Wextra -Werror

SOURCES		=	libft/ft_putnbr_fd.c libft/ft_strlen.c\
				libft/ft_putchar_fd.c libft/ft_atoi.c

OBJECTS		=	$(SOURCES:.c=.o)

SERVER_SRC	=	ft_server.c

SERVER_B	=	server

CLIENT_SRC	=	ft_client.c

CLIENT_B	=	client

BONUS_OBJS	=	ft_server_bonus.o ft_client_bonus.o


all: $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SERVER_SRC:.c=.o) $(OBJECTS)
			$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_B): $(CLIENT_SRC:.c=.o) $(OBJECTS)
			$(CC) $(CFLAGS) -o $@ $^

bonus:
	@make SERVER_SRC="ft_server_bonus.c" CLIENT_SRC="ft_client_bonus.c" all

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C ./libft
	rm -rf $(OBJS) $(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o) $(BONUS_OBJS)

fclean: clean
	rm -f $(SERVER_B) $(CLIENT_B) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
