# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:02:44 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/16 16:03:02 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Zombie.cpp zombieHorde.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Zombie
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
