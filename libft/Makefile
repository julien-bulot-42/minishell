#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 01:10:18 by jbulot            #+#    #+#              #
#    Updated: 2026/03/04 01:14:38 by jbulot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.
SRC = \
	src/ft_strlen.c \
	src/ft_strdup.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
