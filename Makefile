# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nino <nino@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 10:00:05 by nino              #+#    #+#              #
#    Updated: 2021/09/05 12:56:56 by nino             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c utils.c address.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "creation of ${NAME}"
	@echo "generating index for ${NAME}"

%.o: %.c
			@$(CC) -o $@ -c $? $(FLAGS)
			@echo "compiling $? to $@"

clean:
	@rm -f $(OBJS)
	@echo "removing ${OBJS}"

fclean: clean
	@rm -f $(NAME)
	@echo "removing ${NAME}"

re: fclean all

.PHONY: fclean re norme all clean
