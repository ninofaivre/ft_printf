# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaivre <nfaivre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 10:00:05 by nino              #+#    #+#              #
#    Updated: 2021/11/29 13:34:57 by nfaivre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

DIR_SRC = src
DIR_OBJ = .obj

INCLUDE = -Iinclude

SRC = $(wildcard $(DIR_SRC)/*.c)
OBJ = $(addprefix $(DIR_OBJ)/, $(subst src/,, $(SRC:.c=.o)))

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c ./include/ft_printf.h
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "creation of ${NAME}"
	@echo "generating index for ${NAME}"

all: $(OBJ) $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "removing $(OBJ)"

fclean: clean
	@rm -rf $(NAME)
	@echo "removing $(NAME)"

re: fclean all

.PHONY: all clean re fclean
