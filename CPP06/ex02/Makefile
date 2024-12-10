# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 18:16:21 by msaadidi          #+#    #+#              #
#    Updated: 2024/12/01 16:39:50 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror  #-fsanitize=address -g3
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = convert

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all