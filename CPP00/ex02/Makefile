# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 18:25:18 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/24 16:55:21 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = BankingSystem

all : $(NAME)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJS)


fclean : clean
	@rm -rf $(NAME)

re : fclean all

