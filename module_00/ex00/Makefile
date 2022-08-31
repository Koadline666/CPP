# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:34:04 by afenzl            #+#    #+#              #
#    Updated: 2022/08/31 17:47:58 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = c++
CPP_FLAGS =  -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRC = ./megaphone.cpp

OBJ = $(SRC:.cpp=.opp)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	rm $(NAME)