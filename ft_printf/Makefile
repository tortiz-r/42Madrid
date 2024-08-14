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

NAME_BONUS = libftprintf_bonus.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = .

OBJ_DIR = $(SRC_DIR)/obj

SRC_DIR_bonus = .

OBJ_DIR_bonus = $(SRC_DIR_bonus)/obj_bonus

SRC =	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/archivo2.c

OBJ = ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

SRC_bonus =	$(SRC_DIR_bonus)/archivo1_bonus.c \
			$(SRC_DIR_bonus)/archivo2_bonus.c

OBJ_bonus =${SRC_bonus:$(SRC_DIR_bonus)/%.c=$(OBJ_DIR_bonus)/%.o}

RM = rm -f

LIBFT_DIR = libft/

LIBFT = libft/libft.a

INCLUDE = -L ./libft -lft

all: $(NAME)

$(NAME): ${OBJ} $(LIBFT)
	@ar rcs ${NAME} ${OBJ} $(INCLUDE)

bonus: fclean $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_bonus) $(LIBFT)
	@ar rcs ${NAME_BONUS} ${OBJ_bonus} $(INCLUDE)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_bonus)/%.o: $(SRC_DIR_bonus)/%.c
	@mkdir -p $(OBJ_DIR_bonus)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR) $(OBJ_DIR_bonus)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C $(LIBFT_DIR)

re:	fclean clean

.PHONY: all bonus clean fclean re


Debería hacer:
primero transforma la libft a un .a
luego crea la libftprintf.a (o libftprintf_bonus.a)
metiendo los archivos de src pasados a .o
y también mete la lib