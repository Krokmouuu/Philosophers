# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:39:07 by bleroy            #+#    #+#              #
#    Updated: 2022/05/26 20:32:13 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philosophers.c \
	   ft_atoi.c \
	   utils.c \
	   threads.c \
	   activity.c \
	   

OBJS = ${SRCS:.c=.o}

NAME = philo

CC = cc

CFLAGS = -Werror -Wall -Wextra -Ofast -g -fsanitize=thread

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re :    fclean all

.PHONY: all clean fclean re
