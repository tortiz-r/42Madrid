/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_prueba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:01:18 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/10 19:23:06 by tortiz-r         ###   ########.fr       */
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
# define BUFFER_SIZE 80
#endif

typedef struct s_line_utils_struct
{
	int							fd;
	int							bytes_read;
	int							read_status;
	int							line_status;
	char						*l_compl;
	char						*l_rem;
	struct s_line_utils_struct	*next;

}								t_line_obj;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*write_buffer(int fd, t_line_obj *line_utils);
char				*distrib_buffer(int optn, char *buffer, 
						t_line_obj *line_obj);
int					check_line(t_line_obj *line_obj);


// char				*write_distrib_buffer(int fd, t_line_obj *line_utils);

t_line_obj			*ft_lstnew(int fd, int read_status, int line_status);
void				ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node);
void				ft_lstclear_num(t_list **lst, void (*del)(void*),
						size_t size);
int					ft_lstsize(t_line_obj *lst);
char				*write_buffer(int fd, t_line_obj *line_utils);
char				*ft_linefusion(char *line1, char *line2, int len);

int	main(void)
{
	// t_list 		*read_node;
	// t_list		*current_ptr;
	// t_list		*temp_node_ptr;
	int			i;
	int			fd;
	char	*result;

	i = 0;
	fd = open("read_txt_short.txt", O_RDONLY);
	// read_node = NULL;
	while (i < 1)
	{
		result = get_next_line(fd);
		printf("La string result es:\n%s\n", result);
		i++;
	}
	// while (i <= 9)
	// {
	// 	printf(AZUL_T"--->read_line<---\n"RESET_COLOR);
	// 	temp_node_ptr = ft_lstnew(write_buffer(fd));

	// 	printf(VERDE_T"La string leída es:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)(temp_node_ptr->content));
	// 	printf(VERDE_T"El linelen del buffer corresp es: %i\n", ft_linelen((char *)(temp_node_ptr->content), '\n'));
	// 	printf(VERDE_T"El tamaño del buffer corresp es: %i\n"RESET_COLOR, ft_size(2, (char *)(temp_node_ptr->content), '\n'));

	// 	ft_lstadd_back(&read_node, temp_node_ptr);
	// 	i++;
	// }

	// 	printf("------- Imprimo los contenidos de la lista\n" RESET_COLOR);
	// current_ptr = read_node;
	// while (current_ptr != NULL)
	// {
	// 	printf(VERDE_T"El nodo contiene:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)current_ptr->content);
	// 	current_ptr = current_ptr->next;
	// }
	return (0);
}

/*------------------------- FUNCIONES A TESTEAR ---------------------------*/

char	*get_next_line(int fd)
{
	static t_line_obj	line_utils = {0, -1, 0, NULL, NULL, NULL};
	int					actual_fd;
	// char				*line_compl;
	// char				*line_rem;
	// int					size;
	char				*buffer;
	char				*check_ptr;

	if (line_utils.read_status == -1)
	{
		actual_fd = fd;
		line_utils.fd = actual_fd;
	printf(AZUL_T"------- Llamamos a write_buffer 1 vez\n" RESET_COLOR);
		buffer = write_buffer(fd, &line_utils);
		if (buffer == NULL)
			return (NULL); //TENDRÍA QUE FREE STRUCT Y POSIBLES SIG NODOS!!!
	printf(AZUL_T"------- Llamamos a write_buffer 1 vez\n" RESET_COLOR);
	printf(VERDE_T"El buffer es:\n"MAGENTA_T"%s\n"RESET_COLOR, buffer);
	printf(AZUL_T"------- Llamo a distrib_buffer\n" RESET_COLOR);
		check_ptr = distrib_buffer_in_strings(buffer, &line_utils);
		if (check_ptr == NULL)
			return (NULL); //FREE COSIS
	printf(VERDE_T"El linelen del buffer corresp es: %i\n" RESET_COLOR, ft_linelen(buffer,'\n'));
	printf(VERDE_T"Line_utils.line_complete es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_utils.l_compl);
	printf(VERDE_T"Line_utils.line_remainder es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_utils.l_rem);
	// line_compl = line_utils.l_compl;
	}
	return (line_utils.l_compl);
}

char	*write_buffer(int fd, t_line_obj *line_utils)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
		return (NULL);
	}
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*distrib_buffer_in_strings(char *buf, t_line_obj *line_utils)
{
	// char			*temp_buf;
	int				len_buf;
	int				len_compl;
	int				len_rem;

	len_buf = ft_linelen(buf, '\0');
	len_compl = ft_linelen(buf, '\n');
	printf(VERDE_T"La variable len_buf es: %i\n", len_buf);
	printf(VERDE_T"La variable len_compl es: %i\n", len_compl);
	len_rem = len_buf - len_compl;
	printf(VERDE_T"La variable len_rem es: %i\n", len_rem);
	// line_utils->l_compl = malloc(len_compl + 1);
	// if (line_utils->l_compl == NULL)
	// {
	// 	//HAY QUE LIBERAR COSIS
	// 	return (NULL);
	// }
	line_utils->l_compl = ft_linefusion(line_utils->l_compl, buf, len_compl);
	line_utils->l_rem = ft_linefusion(line_utils->l_rem, buf+len_compl,len_rem);
	printf("pre-buf\n");
	free(buf);
	printf("post-buf\n");
	return (line_utils->l_compl);
}

char	*ft_linefusion(char *line1, char *line2, int len)
{
	char	*line_result;
	int		i;
	int		j;
	int		line1_len;

	i = 0;
	j = 0;
	printf(AZUL_T"Me meto en linefusion!! :) \n"RESET_COLOR);
	// printf(VERDE_T"Line1 es:\n"MAGENTA_T"%s\n", line1);
	//printf(VERDE_T"Line2 es:\n"MAGENTA_T"%s\n", line2);
	line1_len = ft_linelen(line1, 0);
	printf(VERDE_T"La variable line1_len es: %i\n", line1_len);
	printf(VERDE_T"La variable input len es: %i\n", len);
	line_result = malloc(line1_len + len + 1);
	printf("El malloc que he hecho es de %i\n", line1_len + len + 1);
	if (line_result == NULL)
		return (NULL);
	while (i < line1_len)
	{
		line_result[i] = line1[i];
		i++;
	}
	printf("hooooolaaaaaa\n");
	free(line1);
	while (i < line1_len + len && line2[j] != '\0')
	{
		line_result[i] = line2[j];
		i++;
		j++;
	}
	line_result[i + 1] = '\0';
	return (line_result);
}

int ft_linelen(char *str, int end)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	printf(VERDE_T"me meto en ft_linelen\n");
	if (str == NULL)
		return (0);
	while (str[size] != '\0' && flag == 0)
	{
		if (str[size] == end)
			flag = 1;
		size++;
	}
	// if (flag == 1 && size < BUFFER_SIZE)
	// 	return (-1);
	// if (flag == 0 && size == 0)
	// 	return (-3);
	// if (flag == 0 && size < BUFFER_SIZE)
	// 	return (-2);
	return (size);
}

/*
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
}*/




/*------------------------- FUNCIONES LST ---------------------------*/

t_line_obj	*ft_lstnew(int fd, int read_status, int line_status)
{
	t_line_obj	*node;

	node = malloc(sizeof(t_line_obj));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->read_status = read_status;
	node->line_status = line_status;
	node->l_compl = NULL;
	node->l_compl = NULL;
	node->next = NULL;
	return (node);
}

int		ft_lstsize(t_line_obj *lst)
{
	int		size;
	t_line_obj	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr!= NULL)
	{
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node)
{
	t_line_obj	*last_ptr;
	int				i;

	if (lst != NULL && new_node != NULL)
	{
		if (lst == NULL)
			lst = new_node;
		else
		{
			last_ptr = lst;
			i = 1;
			while (i < ft_lstsize(lst))
			{
				last_ptr = last_ptr->next;
				i++;
			}
			last_ptr->next = new_node;
		}
	}
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
