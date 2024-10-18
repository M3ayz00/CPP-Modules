# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 12:58:16 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/18 14:47:45 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Harl

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
