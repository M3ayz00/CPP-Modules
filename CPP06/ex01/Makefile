# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 18:16:21 by msaadidi          #+#    #+#              #
#    Updated: 2024/12/01 15:36:46 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror  #-fsanitize=address -g3
SRCS = main.cpp Serializer.cpp Data.cpp
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