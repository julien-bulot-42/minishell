#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 23:06:27 by jbulot            #+#    #+#              #
#    Updated: 2026/03/03 23:56:56 by jbulot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes
READLINE = -lreadline

SRC = \
	src/core/main.c \
	src/signals/signals.c \
	src/lexer/token.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(READLINE) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
