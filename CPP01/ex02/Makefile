# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 14:09:29 by msaadidi          #+#    #+#              #
#    Updated: 2024/10/17 14:09:42 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Ref_Ptr
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
