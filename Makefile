# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 11:41:27 by eel-orch          #+#    #+#              #
#    Updated: 2021/06/08 13:35:02 by eel-orch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SERVER_SRC = server.c
SERVER_OBJ = server.o

CLIENT_SRC = client.c
CLIENT_OBJ = client.o


all : $(NAME)

$(SERVER_OBJ) : $(SERVER_SRC)
$(CLIENT_OBJ) : $(CLINET_SRC)

$(NAME) : $(SERVER_OBJ) $(CLIENT_OBJ)
		gcc -Wall -Werror -Wextra -o server $(SERVER_OBJ)
		gcc -Wall -Werror -Wextra -o client $(CLIENT_OBJ)
clean :
	rm -rf  $(SERVER_OBJ) $(CLIENT_OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

