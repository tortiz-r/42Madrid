# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:14:00 by tortiz-r          #+#    #+#              #
#    Updated: 2024/02/24 19:45:19 by tortiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c

OBJ = ${SRC:.c=.o}

HEADS = -I./libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ${OBJ} libft.h
	ar rcs ${NAME} ${OBJ}

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
