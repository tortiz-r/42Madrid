/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:01:18 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/19 11:58:10 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
# define BUFFER_SIZE 20
#endif

typedef struct s_line_utils_struct
{
	int							fd;
	int							read_status;
	int							line_status;
	char						*line_compl;
	char						*line_rem;
	struct s_line_utils_struct	*next;

}								t_line_utils;

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
// t_list				*write_to_buffer(int fd, t_list *read_node);
char				*write_buffer(int fd);


int	ft_size(int inp, void *ptr, int end)
{
	int				len;
	t_line_utils	*current_ptr;

	len = 0;
	current_ptr = ptr;
	if (inp == 1)
	{
		while (((char *)ptr)[len] != end)
			len++;
	}
	if (inp == 2)
	{
		while (((char *)ptr)[len] != end && ((char *)ptr)[len] != '\0')
			len++;
	}
	if ((inp == 1 || inp == 2) && len < BUFFER_SIZE)
		return (-1);
	else if (inp == 1 || inp == 2)
		return (len);
	while (current_ptr != NULL)
	{
		current_ptr = current_ptr->next;
		len++;
	}
	return (len);
}
int ft_linelen(char *str, int end)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (str[size] != '\0' && flag == 0)
	{
		if (str[size] == end)
			flag = 1;
		size++;
	}
	if (flag == 1 && size < BUFFER_SIZE)
		return (-1);
	if (flag == 0 && size == 0)
		return (-3);
	if (flag == 0 && size < BUFFER_SIZE)
		return (-2);
	return (size);
}

int	main(void)
{
	t_list 		*read_node;
	t_list		*current_ptr;
	t_list		*temp_node_ptr;
	int			i;
	int			fd;
	// char	*result;

	i = 0;
	fd = open("read_txt_short.txt", O_RDONLY);
	read_node = NULL;
		printf("------- Llamamos a write_to_buffer 5 veces\n" RESET_COLOR);
	while (i <= 9)
	{
		printf(AZUL_T"--->read_line<---\n"RESET_COLOR);
		temp_node_ptr = ft_lstnew(write_buffer(fd));

		printf(VERDE_T"La string leída es:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)(temp_node_ptr->content));
		printf(VERDE_T"El linelen del buffer corresp es: %i\n", ft_linelen((char *)(temp_node_ptr->content), '\n'));
		printf(VERDE_T"El tamaño del buffer corresp es: %i\n"RESET_COLOR, ft_size(2, (char *)(temp_node_ptr->content), '\n'));

		ft_lstadd_back(&read_node, temp_node_ptr);
		i++;
	}

		printf("------- Imprimo los contenidos de la lista\n" RESET_COLOR);
	current_ptr = read_node;
	while (current_ptr != NULL)
	{
		printf(VERDE_T"El nodo contiene:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)current_ptr->content);
		current_ptr = current_ptr->next;
	}

	//printf("el tamaño de BIG es: %lu\n el tamañño de SMALL es: %lu \n", sizeof(nodoBIG_ptr), sizeof(nodoSMALL_ptr));
	// result = get_next_line(fd);
	// printf("%s\n", *result);
}

/*------------------------- FUNCIONES A TESTEAR ---------------------------*/

char	*write_buffer(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
		return (NULL);
	}
	read(fd, buffer, BUFFER_SIZE);
	if (*buffer == 0)
		printf("ATENCION!!!!!\n");
	return (buffer);
}
t_list	*write_to_buffer(int fd, t_list **read_node)
{
	// int			read_size;
	char		*buffer;
	t_list		*nodo;

	buffer = malloc(BUFFER_SIZE);
	// CONTROLAR CÓMO ESTÁ LA write_buffer_calls
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA***
		return (NULL);
	}
	printf(AZUL_T"--->read_line<---\n"RESET_COLOR);
	// printf(MAGENTA_T"Buffer_size es: %i\n" RESET_COLOR, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	nodo = ft_lstnew(buffer);
	if (*read_node == NULL)
		*read_node = nodo;
	else
		ft_lstadd_back(read_node, nodo);
	// read_size += strlen((char *) buffer);
	if (*buffer == 0)
		printf("ATENCION!!!!!\n");
	printf(VERDE_T"La string leída es:\n"MAGENTA_T"%s\n"RESET_COLOR, buffer);
	printf(VERDE_T"El linelen del buffer corresp es: %i\n", ft_linelen(buffer, '\n'));
	printf(VERDE_T"El tamaño del buffer corresp es: %i\n"RESET_COLOR, ft_size(2, buffer, '\n'));
	// if (read_size == BUFFER_SIZE)
	// {
	// 	flag ++;
	// 	//esto no tiene sentido, no??
	// 	//flag = write_buffer(fd, flag);
	// 	//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	// }
	return (*read_node);
}


// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str_result;

// 	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (str_result == NULL)
// 		return (NULL);
// 	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
// 	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
// 	return (str_result);
// }

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