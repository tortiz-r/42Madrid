# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:14:00 by tortiz-r          #+#    #+#              #
#    Updated: 2024/11/25 13:26:26 by tortiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   ft_isalpha.c \
	    ft_isdigit.c \
	    ft_isalnum.c \
	    ft_isascii.c \
	    ft_isprint.c \
	    ft_strlen.c \
	    ft_memset.c \
	    ft_bzero.c \
	    ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
	    ft_toupper.c \
	    ft_tolower.c \
	    ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
        
OBJ = ${SRC:.c=.o}

SRC_BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ_BONUS = ${SRC_BONUS:.c=.o}

HEADS = -I./libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ${OBJ} libft.h
	ar rcs ${NAME} ${OBJ}

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

bonus: ${OBJ} ${OBJ_BONUS} libft.h
	ar rcs ${NAME} ${OBJ} ${OBJ_BONUS}

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
