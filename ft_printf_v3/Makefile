# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 10:18:49 by tortiz-r          #+#    #+#              #
#    Updated: 2024/08/14 13:59:43 by tortiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = .

OBJ_DIR = $(SRC_DIR)

SRC =	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_itoa.c \
		$(SRC_DIR)/ft_u_itoa.c \
		$(SRC_DIR)/ft_hex_itoa.c \
		$(SRC_DIR)/ft_str_ptr_hex.c \
		$(SRC_DIR)/libft_str_utils.c \
		$(SRC_DIR)/libft_utils2.c

OBJ = ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

HEADS = ft_printf.h

RM = rm -f

all: $(NAME)

$(NAME): ${OBJ}
	@ar rcs ${NAME} ${OBJ}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ)

fclean: clean
	@$(RM) $(NAME)


re:	fclean clean

.PHONY: all bonus clean fclean re

#Debería hacer:
#primero transforma la libft a un .a
#luego crea la libftprintf.a (o libftprintf_bonus.a)
#metiendo los archivos de src pasados a .o
#y también mete la lib
#$(SRC_DIR)/ft_str_toupper.c $(SRC_DIR)/ft_str_ptr_hex.c
