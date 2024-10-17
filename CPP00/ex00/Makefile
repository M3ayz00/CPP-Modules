# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:29:32 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/17 13:49:24 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
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
