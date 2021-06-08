# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 11:41:27 by eel-orch          #+#    #+#              #
#    Updated: 2021/06/08 12:56:00 by eel-orch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = talk

SERVER = server.c
SERVER_ = server

CLIENT = client.c
CLIENT_ = client

all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra $(SERVER) -o $(SERVER_)
	gcc -Wall -Werror -Wextra $(CLIENT) -o $(CLIENT_)
clean :
	rm -rf $(CLIENT_) $(SERVER_)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : $(NAME)

