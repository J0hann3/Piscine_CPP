# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:31:49 by jvigny            #+#    #+#              #
#    Updated: 2023/11/26 19:05:17 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Weapon
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

HEADERS = HumanA.hpp \
			HumanB.hpp \
			Weapon.hpp

SRCS = HumanA.cpp \
		HumanB.cpp \
		main.cpp \
		Weapon.cpp

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