# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 13:30:04 by jvigny            #+#    #+#              #
#    Updated: 2024/01/16 19:02:11 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RealType
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

SRCS = Base.cpp \
		Utils.cpp \
		main.cpp

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