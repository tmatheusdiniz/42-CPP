# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 14:25:20 by mreinald          #+#    #+#              #
#    Updated: 2025/10/19 14:29:33 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = scavTrap

CPP         = c++
CPPFLAGS    = -g -Wall -Wextra -Werror -std=c++98

SRC         = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ         = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
