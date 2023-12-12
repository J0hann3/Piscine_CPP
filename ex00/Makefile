# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:31:49 by jvigny            #+#    #+#              #
#    Updated: 2023/12/12 13:03:28 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

HEADERS = Zombie.hpp

SRCS = main.cpp \
		Zombie.cpp \
		randomChump.cpp \
		newZombie.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all:	$(NAME)

-include $(DEPS)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o:%.cpp	Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS) $(DEPS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re