# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 15:32:06 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/17 13:48:41 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Zombie

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJS)


fclean : clean
	@rm -rf $(NAME)

re : fclean all

