/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:01:18 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/06 22:17:48 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include <sys/stat.h>
# include <fcntl.h>

#define RESET_COLOR	"\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define ROJO_T	"\x1b[31m"
#define VERDE_T	"\x1b[32m"
#define AZUL_T	"\x1b[34m"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear_num(t_list **lst, void (*del)(void*), size_t size);

char				*ft_strjoin(char *s1, char *s2);
t_list				*write_to_buffer(int fd, int write_buffer_calls, t_list **read_list);

int	main(void)
{
	t_list 		*read_list;
	t_list		*current_ptr;
	int			i;
	int			fd;
	static int	write_buffer_calls;
	// char	*result;


	i = 0;
	write_buffer_calls = 1;

	fd = open("leer.txt", O_RDONLY);
	read_list = NULL;
		printf("------- Llamamos a write_to_buffer 5 veces\n" RESET_COLOR);
	while (i <= 5)
	{
		read_list = write_to_buffer(fd, write_buffer_calls, &read_list);
		i++;
	}

		printf("------- Imprimo los contenidos de la lista\n" RESET_COLOR);
	current_ptr = read_list;
	while (current_ptr != NULL)
	{
		printf("El nodo contiene: %s\n", (char *)read_list->content);
		current_ptr = current_ptr->next;
	}

	//printf("el tamaño de BIG es: %lu\n el tamañño de SMALL es: %lu \n", sizeof(nodoBIG_ptr), sizeof(nodoSMALL_ptr));
	// result = get_next_line(fd);
	// printf("%s\n", *result);
}

/*------------------------- FUNCIONES A TESTEAR ---------------------------*/


t_list	*write_to_buffer(int fd, int write_buffer_calls, t_list **read_list)
{
	// int			read_size;
	char		*buffer;
	t_list		*nodo;

	buffer = malloc(BUFFER_SIZE);
	// CONTROLAR CÓMO ESTÁ LA write_buffer_calls
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA***
		return (-1);
	}
	printf(AZUL_T"--->read_line<---\n");
	// printf(MAGENTA_T"Buffer_size es: %i\n" RESET_COLOR, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	nodo = ft_lstnew(buffer);
	if (read_list == NULL)
		*read_list = nodo;
	else
		ft_lstadd_back(read_list, nodo);
	// read_size += strlen((char *) buffer);
	printf(VERDE_T"La string leída es: %s\n"RESET_COLOR, buffer);
	write_buffer_calls++;
	// if (read_size == BUFFER_SIZE)
	// {
	// 	flag ++;
	// 	//esto no tiene sentido, no??
	// 	//flag = write_buffer(fd, flag);
	// 	//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	// }
	return (*read_list);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_result;

	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_result == NULL)
		return (NULL);
	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (str_result);
}

/*---------------------------- FUNCIONES LST ------------------------------*/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr != NULL)
	{
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ptr;
	size_t	i;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_ptr = *lst;
			i = 1;
			while (i < (size_t)ft_lstsize(*lst))
			{
				last_ptr = last_ptr->next;
				i++;
			}
			last_ptr->next = new;
		}
	}
}
void	ft_lstclear_num(t_list **lst, void (*del)(void*), size_t size)
{
	t_list	*next_node_ptr;
	size_t	i_clear;

	next_node_ptr = *lst;
	i_clear = 0;
	while (*lst != NULL && i_clear < size)
	{
		del((*lst)->content);
		next_node_ptr = (*lst)->next;
		free(*lst);
		*lst = next_node_ptr;
		i_clear++;
	}
}