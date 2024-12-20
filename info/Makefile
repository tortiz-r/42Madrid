# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 10:46:10 by tortiz-r          #+#    #+#              #
#    Updated: 2024/08/14 13:43:39 by tortiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ejemplo para incluir libft en un proyecto
#1º copiar al proyecto la carpeta de la libft (sin los archivos .* como .gitnsq)

#en este ejemplo, no hay carpeta src per se
#en este ejemplo hay carpeta "bonus" que se compila aparte con una regla bonus

NAME = libftprintf.a

NAME_BONUS = archivo_bonus.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = .

OBJ_DIR = ./obj

SRC_DIR_bonus = ./bonus

OBJ_DIR_bonus = $(SRC_DIR_bonus)/obj

SRC =	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/archivo2.c

OBJ = ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

SRC_bonus = $(SRC_DIR_bonus)/archivo_bonus1.c \
			$(SRC_DIR_bonus)/archivo_bonus2.c

OBJ_bonus = ${SRC_bonus:$(SRC_DIR_bonus)/%.c=$(OBJ_DIR_bonus)/%.o}

RM = rm -f

LIBFT_DIR = libft/

INCLUDE = -L ./libft -lft

all: $(NAME)

$(NAME): ${OBJ}
	@echo "Compiling..."
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo "Program compiled✅"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_bonus)
	@echo "Compiling bonus..."
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_bonus) $(INCLUDE) -o $(NAME_BONUS)
	@echo "Bonus compiled✅"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_bonus)/%.o: $(SRC_DIR_bonus)/%.c
	@mkdir -p $(OBJ_DIR_bonus)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR) $(OBJ_DIR_bonus)
	@make -s clean -C $(LIBFT_DIR)
	@echo "Objects deleted!"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) 
	@make -s fclean -C $(LIBFT_DIR)
	@echo "All cleaned!"

re:	fclean clean

.PHONY: all bonus clean fclean re

# COMENTARIOS

# INCLUDE:
# el -L dice en qué directorio está la libft
# el -lft es para que el linker busque static y dinamic librerias en el dir .
#-lft especifica que la libreria se llama lib'ft'

# !!!!!!!!no termino de dominar lo que hace el -lft !!!!!!!!

# COMPILANDO:
# la option -s es para que realice la orden "silently"
# la option -C es para darle a la orden un directorio
# la option -o permite escribir a continuacion el nombre del outputfile
# aquí no usamos el comando ar pero usando el comando ar